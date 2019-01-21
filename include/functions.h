//------Defining the motor ports.------
#define FLMotorport 11
#define FRMotorport 20
#define BLMotorport 12
#define BRMotorport 19
#define Armport 13
#define Intakeport 8
#define Shooter1port 9
#define Shooter2port 10

//------Defining the motors.------
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

extern int selection;
extern const char *titles[5];
extern void (*scripts[5])();

//------This veriable helps control the direction of the drive train.------
extern bool isForward;

extern bool isBreaking;

//------These map the joisticks to be used later for turning motors.------
extern int LeftControls;
extern int RightControls;
extern int ArmControls;
extern int IntakeControls;

//------sets drive trains target, but does not wait for them to reach their target.------
void driveForDistance(double leftInches, double rightInches);

//------Function for setting the drive trian breaks.------
void brakeDriveTrain();

//------Function for releasing the drive train breaks.------
void unBrakeDriveTrain();

//------Function for seting the cap flipper side to be the front side.------
void setBackwords();

//------Function for seting the ball shooter side to be the front side.------
void setForwards();

//------Function for turning on the shooter.------
void shooterOn(int velocity = 0);

//------Function for turning off the shooter.------
void shooterOff();

void LeftNear();


void LeftFar();


void RightNear();


void RightFar();


void SkillsAutonLeftNear();
