// Defining ports
#define FLMotorport 9
#define FRMotorport 2
#define BLMotorport 10
#define BRMotorport 1
#define Armport 8
#define Intakeport 20
#define Shooter1port 12
#define Shooter2port 13
#define GYRO_PORT 6
#define TopIntakeSensorPort 8
#define BottomIntakeSensorPort 7

// Defining motor and sensor objects
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
extern pros::ADIDigitalIn TopIntakeSensor;
extern pros::ADIDigitalIn BottomIntakeSensor;
extern pros::ADIUltrasonic front_ultrasonic;
extern pros::ADIUltrasonic back_ultrasonic;

// These are information veriables that tell you when things are happening on the robot
extern bool IsBreaking;
extern bool IsForward;
extern bool IsOverHeigh;
extern int ArmCeiling;

// Defining joistic veriables
extern int LeftControls;
extern int RightControls;
extern int ArmControls;
extern int IntakeControls;

// Boolian that determins wheather we park in auton
extern bool IsParking;


// Function from Arm.cpp
void Arm_fn(void* param);


// Function for Intake.cpp
void Intake_fn(void* param);


// Functions for Shooter.cpp
void Shooter_fn(void* param);
void ShooterOn(int velocity = 200);
void ShooterOff();
void BackToTopFlag();


// Functions for DriveTrain.cpp
void DriveTrain_fn(void* param);
void Rotate(int turn, int speed);
void Driver_Rotate(double turn, int speed);
void BrakeDriveTrain();
void UnBrakeDriveTrain();
void SetBackwords();
void SetForwards();
void Front_Ultrasonic_Drive(double distance, int speed);
void Back_Ultrasonic_Drive(double distance, int speed);

/*
    Blocks the program from continuing until the drive train has
    reached its target position set by the Drive function. 
*/
bool AtDistanceDriveGoal(int threshold);
void Drive(double leftInches, double rightInches, int speed);
int GyroPos();


// Functions for Terminal.cpp
void Diagnostics_fn(void* param);


// Functions for autonomous.cpp
void RedFlag();
void RedCap();
void BlueFlag();
void BlueCap();
void SkillsAuton();
void IffySkillsAuton();


void LCDScriptExecute();
// Veriables and funstions for auton selector.
extern int selection;
extern const char *titles[5];
extern void (*scripts[5])();
