const int DC1in1 = 2;//leftwheel
const int DC1in2 = 4;
const int ENA1 = 5;
const int DC2in1 = 8;//rightwheel
const int DC2in2 = 7;
const int ENA2 = 6;
const int irRight = 11;
const int irLeft = 9;
const int irCenter = 10;

int n = 0;
int k = 1;

void setup() {
 
  pinMode(DC1in1, OUTPUT);
  pinMode(DC1in2, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(DC2in1, OUTPUT);
  pinMode(DC2in2, OUTPUT);
  pinMode(ENA2, OUTPUT);

  pinMode(irRight, INPUT);
  pinMode(irLeft, INPUT); 
  pinMode(irCenter, INPUT);

  //analogWrite(ENA1, 130);
  //analogWrite(ENA2, 130); 
}

void loop(){
    n = n+1;
    do{
      
      Follow_foward();
      
      if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1)){

          //lifting function will be placed here
          
          Stop();
          delay(1000);

          //first stop and moves backward.
          if(n==1){
               do{
                    digitalWrite(DC1in1, HIGH);
                    digitalWrite(DC1in2, LOW);
                    digitalWrite(DC2in1, LOW);
                    digitalWrite(DC2in2, HIGH);
                    analogWrite(ENA1, 90);
                    analogWrite(ENA2, 130);
                    delay(100);
                    //Follow_backward(); //test this later
                    //delay(2000);
               }while((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 0)); 
               //while((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1));  with follow_backward 
               delay(1000);
               do{

                    digitalWrite(DC1in1, LOW);
                    digitalWrite(DC1in2, HIGH);
                    digitalWrite(DC2in1, HIGH);
                    digitalWrite(DC2in2, LOW);
                    analogWrite(ENA1, 140);
                    analogWrite(ENA2, 90);
                    delay(100);
               }while((digitalRead(irCenter) == 1));
               delay(1000);
               break;
                       
          }
          //Second stop and make a turn
          if(n == 2){
              do{
                
                  analogWrite(ENA1, 140);
                  analogWrite(ENA2, 90);
                  digitalWrite(DC1in1, LOW);
                  digitalWrite(DC1in2, HIGH);
                  digitalWrite(DC2in1, LOW);
                  digitalWrite(DC2in2, HIGH);

                  //delay(100);

              }while((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0));

              n= n-2;
              delay(1000);
              break;
            
          }

        
      }
      
    }while(k==1); 

}
  



void pallet_out(){
//LIFTING MOTOR MOVES UP LITTLE BIT 
//ex) 1cm up
  
  
}

void pallet_in(){

//lifting motor moves down a bit
//ex) 1cm down
}


void Follow_foward(){
  
   analogWrite(ENA1, 130);
   analogWrite(ENA2, 130); 
   
   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0)){forward();   }

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0)){ turnLeft_A(); }

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 0)){ turnLeft_B(); }

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1)){ turnRight_A();}

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 1)){ turnRight_B(); }

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1)){Stop();}

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 0)){forward();}

}

//backward function not a perfect
void Follow_backward(){

   analogWrite(ENA1, 100);
   analogWrite(ENA2, 100);

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0)){ backward();   }

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0)){turnRight_A2();}

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 0)){turnRight_B2();}
   

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1)){ turnLeft_A2();}

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 1)){ turnLeft_B2(); }
   

   if((digitalRead(irLeft) == 1)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 1)){ backward();}

   if((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 0)&&(digitalRead(irRight) == 0)){backward();}

}

void whole_turn(){


  do{
    analogWrite(ENA1, 160);
    analogWrite(ENA2, 160);
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);

    delay(10);
    
  }while((digitalRead(irLeft) == 0)&&(digitalRead(irCenter) == 1)&&(digitalRead(irRight) == 0));
  
  Stop();
  delay(1000);

}

void forward(){
     
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, HIGH);
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);
    //analogWrite(ENA1, 180);
    //analogWrite(ENA2, 100);
}

void backward(){
     
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, HIGH);
    //analogWrite(ENA1, 200);
    //analogWrite(ENA2, 110);
}

void turnRight_A(){
    
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, HIGH);
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, LOW);
    analogWrite(ENA1, 150);
    //analogWrite(ENA2, 110);
}
void turnRight_B(){
    
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, HIGH);
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, HIGH);
    analogWrite(ENA1,130);
    analogWrite(ENA2, 130);
}

void turnLeft_A(){
    
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);
    //analogWrite(ENA1, 190);
    analogWrite(ENA2, 150);
  
}
void turnLeft_B(){
    
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);
    analogWrite(ENA1, 130);
    analogWrite(ENA2, 130);
  
}

void Stop(){
   
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, LOW);
    // analogWrite(ENA1, 85);
    //analogWrite(ENA2, 100);
}




//move backward
void forward2(){
     
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, HIGH);
    //analogWrite(ENA1, 200);
    //analogWrite(ENA2, 100);
}

void turnRight_A2(){
    
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, LOW); 
    digitalWrite(DC2in2, HIGH);
    analogWrite(ENA1, 170);
    analogWrite(ENA2, 170);
}

void turnRight_B2(){
    
    digitalWrite(DC1in1, LOW);
    digitalWrite(DC1in2, HIGH);
    digitalWrite(DC2in1, LOW); 
    digitalWrite(DC2in2, HIGH);
    analogWrite(ENA1, 200);
    analogWrite(ENA2, 170);
}

void turnLeft_A2(){
    
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW); //LOW
    digitalWrite(DC2in1, LOW);
    digitalWrite(DC2in2, LOW);
    analogWrite(ENA1, 170);
    analogWrite(ENA2, 170);
  
}

void turnLeft_B2(){
    
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW); //LOW
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);
    analogWrite(ENA1, 170);
    analogWrite(ENA2, 200);
  
}


/*TURNING PART
 *   delay(1000);
    do{
    digitalWrite(DC1in1, HIGH);
    digitalWrite(DC1in2, LOW);
    digitalWrite(DC2in1, HIGH);
    digitalWrite(DC2in2, LOW);
    analogWrite(ENA1, 110);
    analogWrite(ENA2, 110);
    delay(500);
    
  }while((digitalRead(irLeft) == 1)||(digitalRead(irRight) == 1));  
  */
  
