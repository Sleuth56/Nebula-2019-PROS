//Defining the motor ports
#define FLMotorport 10
#define FRMotorport 2
#define BLMotorport 9
#define BRMotorport 1
#define Armport 8
#define Intakeport 13
#define Shooter1port 12
#define Shooter2port 14
#define GYRO_PORT 1

//Defining the motors
extern pros::Motor FLMotor;
extern pros::Motor BLMotor;
extern pros::Motor FRMotor;
extern pros::Motor BRMotor;
extern pros::Motor Intake;
extern pros::Motor Arm;
extern pros::Motor Shooter1;
extern pros::Motor Shooter2;
extern pros::Controller master;
extern pros::Controller partner;
extern pros::ADIGyro gyro;

//This veriable helps control the direction of the drive train
extern bool IsBreaking;
extern bool IsForward;
extern bool IsShooterHot;
extern bool IsFlipping;
extern bool IsOverHeigh;
extern int flipTarget;
extern int flipingSpeed;
extern int ArmCeiling;

//These map the joisticks to be used later for turning motors
extern int LeftControls;
extern int RightControls;
extern int ArmControls;
extern int IntakeControls;

//------Function for Arm.cpp.------
  void Arm_fn(void* param);


//------Function for Intake.cpp.------
  void Intake_fn(void* param);

  //Functions for Shooter.cpp.
  void Shooter_fn(void* param);

  //Function for turning on the shooter
  void ShooterOn(int velocity = 200);

  //Function for turning off the shooter
  void ShooterOff();

  //Function for shooting booth top flags.
  void ShootTwice();


//------Functions for DriveTrain.cpp.------
  void DriveTrain_fn(void* param);

  //Returns true/false as to wheter the drive wheels have
  //reached their position goal set by driveForDistance
  bool AtDistanceDriveGoal(int threshold);

  //Sets drive trains target, but does not wait for them to reach their target
  void Drive(double leftInches, double rightInches, int speed);

  //Turns the robot to the target position
  void Rotate(double turn, int speed);

  //Function for setting the drive trian breaks
  void BrakeDriveTrain();

  //Function for releasing the drive train breaks
  void UnBrakeDriveTrain();

  //Function for seting the cap flipper side to be the front side
  void SetBackwords();

  //Function for seting the ball shooter side to be the front side
  void SetForwards();
  
  //Function for getting the gyros position
  int GyroPos();


//------Functions for autonomous.cpp.------
  //Function for the red flag side of the field
  void RedFlag();

  //Function for the red cap side of the field
  void RedCap();

  //Function for the blue flag side of the field
  void BlueFlag();

  //Function for the blue cap side of the field
  void BlueCap();

  //Function for skills auton
  void SkillsAuton();

  //Function for starting the right auton program
  void LCDScriptExecute();

  //Veriables and funstions for auton selector
  extern int selection;
  extern const char *titles[5];
  extern void (*scripts[5])();
