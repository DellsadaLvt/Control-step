short int array_tt[25]= {1234, 1243, 1324, 1342, 1423, 1432, 2134, 2143, 2314, 2341, 2413, 2431, 3124, 3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321};
char array_chan[6] = { 0, 7, 6, 5, 4};
int i, j, dem=0;
/********************************************************************************************************************/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for( i=1; i<5; i++)
    pinMode(array_chan[i], OUTPUT);
  pinMode(8, INPUT_PULLUP);
}
/********************************************************************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
     if(digitalRead(8)==0)
     {
        dem++;
        if(dem == 2)
          dem=0;
        Serial.println(dem);
        while(digitalRead(8)==0);
        
     }
     if(dem==0)
          sequence_kich(array_tt[2]);
      
      if(dem==1)
       sequence_kich(4231);
//      delay(2000);
     }
     
  

/********************************************************************************************************************/
void kichChan(short int x)
{
  digitalWrite(array_chan[x], HIGH);
  for(i=1; i< 5; i++)
    if(i!=x)
      digitalWrite(array_chan[i], LOW);
}
/********************************************************************************************************************/
void sequence_kich(short int x)
{
  kichChan(x/1000);
  delay(5);
  kichChan((x/100)%10);
  delay(5);
  kichChan((x/10)%10);
  delay(5);
  kichChan(x%10);
  delay(5);
}
/********************************************************************************************************************/
