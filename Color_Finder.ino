//---------NJarpa
//--------Color Finder TFT 3.2 240x320 ILI9341

//-----Libraries
#include <UTFT.h> 
#include <URTouch.h>

//==== Parameters should be adjusted to your Display/Shield model
UTFT    myGLCD(ILI9341_16,38,39,40,41); 
URTouch  myTouch( 6, 5, 4, 3, 2);
//------- Images used
extern unsigned int less45x45[0x7E9];
extern unsigned int add45x45[0x7E9];
//-----Fonts used
extern uint8_t GroteskBold24x48[];
extern uint8_t BigFont[];
//-----Variables RGB
int R = 128;
int G = 128;
int B = 128;
//-----Variables x y for touch function
int x, y ;

void setup() {
  // Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  HomePage(); //Call Custom Functions
  SetColor();

}

void loop() {
 myGLCD.setColor(VGA_LIME);
 myGLCD.setFont(GroteskBold24x48);
 myGLCD.printNumI(R,105,80,3,'0');
 myGLCD.printNumI(G,105,136,3,'0');
 myGLCD.printNumI(B,105,192,3,'0');



 
//-----Button functions
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X coordinate where the screen has been pressed
      y=myTouch.getY(); // Y coordinates where the screen has been pressed

//--------- Red
        // If we press less Button R
        if ((x>=45) && (x<=85) &&(y>=80) && (y<=128)) {
          if(R>0){
          R-- ;
          }
         
       else{
        R=0;
       }

        } 
        
        // If we press add Button R
        if ((x>=205) && (x<=250) &&(y>=80) && (y<=128)) {
          if(R<255){
          R++ ;
          }

       else{
        R=255;
       }
//------Green
        } 
        // If we press less Button G
        if ((x>=45) && (x<=85) &&(y>=136) && (y<=184)) {
          if(G>0){
          G-- ;
          }
         
       else{
        G=0;
       }

        } 
        
        // If we press add Button G
        if ((x>=205) && (x<=250) &&(y>=136) && (y<=184)) {
          if(G<255){
          G++ ;
          }

       else{
        G=255;
       }
//-------Blue
        }   

        // If we press less Button B
        if ((x>=45) && (x<=85) &&(y>=192) && (y<=240)) {
          if(B>0){
          B-- ;
          }
         
       else{
        B=0;
       }

        } 
        
        // If we press add Button B
        if ((x>=205) && (x<=250) &&(y>=192) && (y<=240)) {
          if(B<255){
          B++ ;
          }

       else{
        B=255;
       }

        }  
         SetColor();                      
}//touch data avaible end
 


  
}//void loop end

void HomePage (){  // 
  myGLCD.setColor(VGA_LIME); // Sets color
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print("Color Finder", CENTER, 0); // Prints the string on the screen 
 
  myGLCD.setColor(VGA_LIME); // Sets color
  myGLCD.setFont(GroteskBold24x48); // Sets font
  myGLCD.print("R", 5, 80); // Prints the string on the screen 
  
  myGLCD.setColor(VGA_LIME); // Sets color
  myGLCD.setFont(GroteskBold24x48); // Sets font
  myGLCD.print("G", 5, 136); // Prints the string on the screen
  
  myGLCD.setColor(VGA_LIME); // Sets color
  myGLCD.setFont(GroteskBold24x48); // Sets font
  myGLCD.print("B", 5, 192); // Prints the string on the screen
  
//-----Draw buttons
  myGLCD.drawBitmap (45, 80, 45, 45,less45x45 );
  myGLCD.drawBitmap (45, 136, 45, 45,less45x45 );
  myGLCD.drawBitmap (45, 192, 45, 45,less45x45 );

  myGLCD.drawBitmap (205, 80, 45, 45,add45x45 );
  myGLCD.drawBitmap (205, 136, 45, 45,add45x45 );
  myGLCD.drawBitmap (205, 192, 45, 45,add45x45 ); 
}

void SetColor (){
  myGLCD.setColor(R,G,B); // Sets color
  myGLCD.setFont(GroteskBold24x48); // Sets font to big
  myGLCD.print("ABC 123", 10, 24); // Prints the string on the screen
  myGLCD.fillRect(205,24,310,72);  
}



