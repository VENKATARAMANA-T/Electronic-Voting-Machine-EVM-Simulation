#include <LiquidCrystal.h>
#define sw1 A0 // Button 1
#define sw2 A1 // Button 2
#define sw3 A2 // Button 3
#define sw4 A3 // Button 4
#define sw5 A4 // Button 5 for result

LiquidCrystal lcd(11,10,9,8,7,6);


int credentials[69][2];
int votedlist[69];
  
int votesCount[4] = {0, 0, 0, 0};
bool accessGranted = false;

 // vv
struct Admin {
  	int adminnumber;
  	int password;
	bool adminaccess;
}A={70,70,false} ; 

struct Admin *sptr=&A;

// vv
union Winner
{
  int winner_index;
};

union Winner w;


void setup() {
  Serial.begin(9600);
  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(13, OUTPUT); // Blue LED
  pinMode(12, OUTPUT); // Green LED
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("VOTING MACHINE");
  lcd.setCursor(0, 1);
  lcd.print("Circuit design");
  delay(1000);

 
  for (int i = 0; i < 69; i++) {
    credentials[i][0] = i + 1;        
    credentials[i][1] = i + 1;
  }

  
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TDP");
  lcd.setCursor(4, 0);
  lcd.print("YCP");
  lcd.setCursor(8, 0);
  lcd.print("JSP");
  lcd.setCursor(12, 0);
  lcd.print("OTH");
}

void loop() {

    lcd.setCursor(0, 0);
    lcd.print("TDP");
    lcd.setCursor(1, 1);
    lcd.print(votesCount[0]);
    lcd.setCursor(4, 0);
    lcd.print("YCP");
    lcd.setCursor(5, 1);
    lcd.print(votesCount[1]);
    lcd.setCursor(8, 0);
    lcd.print("JSP");
    lcd.setCursor(9, 1);
    lcd.print(votesCount[2]);
    lcd.setCursor(12, 0);
    lcd.print("OTH");
    lcd.setCursor(13, 1);
    lcd.print(votesCount[3]);
  if (!accessGranted) {
    verifyUser();
  } else {
    
    if (sptr->adminaccess)
    {
		getResult();
    }
    else{
      ReadSwitch1();
      ReadSwitch2();
      ReadSwitch3();
      ReadSwitch4();
    }
  }
}


//venkat
void verifyUser() { 
  Serial.println("Please enter Roll Number and Password.");
  
  int rollNo = getRollNo();
  int password = getPassword();

  if (isValidUser(rollNo, password)) {
    accessGranted = true;
    Serial.println("Access Granted.");
  } else {
    Serial.println("Wrong Entry. Try Again.");
  }
}


int getRollNo() {
  Serial.print("Enter Roll Number: ");
  while (!Serial.available());
  int rollNo = Serial.parseInt();
  Serial.println(rollNo);
  return rollNo;
}

int getPassword() {

  Serial.print("Enter Password: ");
  while (!Serial.available());
  int password = Serial.parseInt();
  Serial.println(password);
  return password;
}

// vv
bool isValidUser(int rollNo, int password) {  
  for (int i = 0; i < 69; i++) {
    if (credentials[i][0] == rollNo && credentials[i][1] == password && votedlist[i]==0) {
      votedlist[i]=1;
      return true;
    }
  }
 
   if (rollNo==sptr->adminnumber && password==sptr->password)
  {
   	sptr->adminaccess=true;
    return true;
  }
  return false;
}

// Kalyan
void ReadSwitch1() {
  if(digitalRead(sw1) == 0) { 
    votesCount[0]++;
    digitalWrite(12, HIGH);
    delay(100);
    while(digitalRead(sw1) == 0);
    digitalWrite(12, LOW);
    delay(100);
    
    accessGranted = false;
  }
}

void ReadSwitch2() {
  if(digitalRead(sw2) == 0) {
    votesCount[1]++;
    digitalWrite(12, HIGH);
    delay(100);
    while(digitalRead(sw2) == 0);
    digitalWrite(12, LOW);
    delay(100);
    
    accessGranted = false;
  }
}

void ReadSwitch3() {
  if(digitalRead(sw3) == 0) {
    votesCount[2]++;
    digitalWrite(12, HIGH);
    delay(100);
    while(digitalRead(sw3) == 0);
    digitalWrite(12, LOW);
    delay(100);
    
    accessGranted = false;
  }
}

void ReadSwitch4() {
  if(digitalRead(sw4) == 0) {
    votesCount[3]++;
    digitalWrite(12, HIGH);
    delay(100);
    while(digitalRead(sw4) == 0);
    digitalWrite(12, LOW);
    delay(100);
    
    accessGranted = false;
  }
}

//Rohit
void getResult() {
  if(digitalRead(sw5) == 0) {
    digitalWrite(13, HIGH);
    int totalVotes = total_votes();
    if (totalVotes) {
      int maxVotes = votesCount[0];
      w.winner_index = 0;
      int tie = 0;
      for (int i = 1; i < 4; i++) {
        if (votesCount[i] > maxVotes) {
          maxVotes = votesCount[i];
          w.winner_index  = i;
          tie = 0;
        } else if (votesCount[i] == maxVotes) {
          tie = 1;
        }
      }
      
      lcd.clear();
      if (tie == 0) {
        switch (w.winner_index) {
          case 0: lcd.print("TDP Wins"); break;
          case 1: lcd.print("YCP Wins"); break;
          case 2: lcd.print("JSP Wins"); break;
          case 3: lcd.print("OTH Wins"); break;
        }
      } else {
        lcd.print("TIE");
      }
      delay(5000);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NO VOTING");
      delay(5000);
    }
    for (int i = 0; i < 4; i++) votesCount[i] = 0;
    lcd.clear();
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    for(int i=0;i<69;i++)
    {
      votedlist[i]=0; 
    }
    sptr->adminaccess=false;
    accessGranted=false;
  }
  
  
}

int total_votes()
{
	int sum = 0;
  
 	for(int i=0;i<4;i++)
    {
      sum=sum+votesCount[i];
    }
	
  return sum;
}
