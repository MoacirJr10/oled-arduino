#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <MFRC522.h>

// ===================== CONFIGURAÇÃO OLED =====================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ===================== CONFIGURAÇÃO RFID =====================
#define PINO_RST 9
#define PINO_SDA 10
MFRC522 rfid(PINO_SDA, PINO_RST);

// ===================== UIDs AUTORIZADOS =====================
// Demonstração: configure UIDs de teste localmente; vazio bloqueia todos.
const char* uid_chaveiro = "";
const char* uid_cartao = "";

void setup() {
  Serial.begin(9600);

  // Inicia display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar o display SSD1306"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Inicia RFID
  SPI.begin();
  rfid.PCD_Init();

  Serial.println("Aproxime a sua tag...");
}

void loop() {
  // Verifica nova tag
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  // Monta UID como string
  String conteudo = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    conteudo.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(rfid.uid.uidByte[i], HEX));
  }
  conteudo.toLowerCase(); // Garante letras minúsculas

  // Não registrar identificadores de cartões.

  // Limpa display e seleciona fonte
  display.clearDisplay();
  display.setFont(&FreeSerif12pt7b);
  display.setCursor(10, 40);

  // Verifica UID e mostra no OLED
  if ((uid_chaveiro[0] && conteudo.substring(1) == uid_chaveiro) || (uid_cartao[0] && conteudo.substring(1) == uid_cartao)) {
    display.print(F("OPEN"));
    Serial.println("Acesso liberado");
  } else {
    display.print(F("DENIED"));
    Serial.println("Acesso negado");
  }

  display.display();

  delay(2000); // Mostra mensagem por 2 segundos
  display.clearDisplay();
  display.display();

  rfid.PICC_HaltA(); // Para comunicação com o cartão
  rfid.PCD_StopCrypto1();
}
