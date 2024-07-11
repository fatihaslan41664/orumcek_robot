
/* Kodla Gitsin
 * Kızıl Ötesi Kod Çözücü ve Test
 * kodlagitsin.blogspot.com
*/

#include <IRremote.h>  //kütüphane indirme adresi:  https://github.com/z3t0/Arduino-IRremote
int RECV_PIN = 12;    // IR alıcısı giriş portu
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  // 2.3.4.5. pinler Ledler için çıkış olarak ayarlandı
  pinMode(2,OUTPUT);   // kırmızı led - led bacağına 330R-1K arası direnç bağlayın
  pinMode(3,OUTPUT);   // kırmızı led - led bacağına 330R-1K arası direnç bağlayın
  pinMode(4,OUTPUT);   // kırmızı led - led bacağına 330R-1K arası direnç bağlayın
  pinMode(5,OUTPUT);   // mavi led - led bacağına 330R-1K arası direnç bağlayın
  Serial.begin(9600);  // seri port ekranbağlantı hızı
  irrecv.enableIRIn(); // Alış başlıyor
     Serial.println("KODLAR:");
}

void loop() {
  if (irrecv.decode(&results)) {

    //Serial.print komutu seriport ekranda satırı yazar yan yana devam eder
    //Serial.println komutu seri port ekranda satırı yazar alt satıra geçer
     Serial.print("HEX> "); 
     Serial.println(results.value, HEX); // Gelen veri hexadecimal (16'lık) tabanda yazılır
     Serial.print("BIN> "); 
     Serial.println(results.value, BIN); // Gelen veri binary (2'lik) tabanda yazılır
     Serial.print("DEC> "); 
     Serial.println(results.value, DEC); // Gelen veri decimal (10'luk)tabanda yazılır
     Serial.println("---------------------------------------");
    
       if(results.value==0x80BF49B6)          // CH... ise 1. Led yansın - bu satırdaki hex kodu elimdeki kumandaya göre yazdım, siz kendinize göre değiştirin  
             digitalWrite(2,HIGH);        
          else if(results.value==0x80BFC936) // CH... ise 2. Led yansın - bu satırdaki hex kodu elimdeki kumandaya göre yazdım, siz kendinize göre değiştirin  
             digitalWrite(3,HIGH);
          else if(results.value==0x80BF33CC) // CH... ise 3. Led yansın - bu satırdaki hex kodu elimdeki kumandaya göre yazdım, siz kendinize göre değiştirin  
             digitalWrite(4,HIGH);
             
          else if(results.value==0x80BF738C){ // CH... ise 1.2.3. Led yansın - bu satırdaki hex kodu elimdeki kumandaya göre yazdım, siz kendinize göre değiştirin  
             digitalWrite(2,HIGH);
             digitalWrite(3,HIGH);
             digitalWrite(4,HIGH);
           }
           
          else {                       // Eğer diğer/başka butonlara basılmış ise 1.2.3.ledler sönsün
             digitalWrite(2,LOW);
             digitalWrite(3,LOW);
             digitalWrite(4,LOW);
             digitalWrite(5,HIGH); // diğer ledler (1.2.3.) sönerken 5.led yansın
             delay(250);           // 5.ledin yanık kalma süresi- mavi led bir süre yansın
             digitalWrite(5,LOW);  // 5.led sönsün
         }    
    irrecv.resume(); // yeni bir değer almak için yola devam ediyoruz
  
  }
  delay(250); // sinyaller karışmasın azıcık bekleyelim
}
