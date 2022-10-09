//Description: This program saves and calculate students' grade.
//LAB: Final Exam Capstone
//Course: CIT 120-T1
//Programmer: Christina Trinh
//Professor: Makhene
//Date: 5/6/21

#include <iostream>
#include <string>
#include<fstream> //header file for fstream
#include <sstream> // header file for converting from string to integer to calculate grades for students
using namespace std;

//function prototypes and descriptions
void banner();
bool valid(string ); // this function checks for validation of file Student#....
bool validate(string); //This function checks for validation of syllabus file
bool validateStudent (int); //This function checks for validation of number of students(input)
void inputFileofStudent (string,int); //This function saves students' grades into an array
void Loads (int); //This function output information in the "third" file(after calculate) for each students
double grade(int, int); //This function calculate grades

//Constant variables and array used in the program
const string Syllabus1= "syllabus.txt";
const string Syllabus2= "syllabus2.txt";
const string file2 = "Student#";
const string file = ".txt";
const int sizeSyll1= 7;
const int sizeSyll2=5;
const double array1[7]={0.05, 0.10, 0.07, 0.08, 0.25, 0.35, 0.10};
const double array2[5]={0.10, 0.20, 0.25, 0.35, 0.10};
string arrSyll[7]; //this array used to store information read from the syllabus that the user chose
string arrStudent[3]; //This array stores the information such as "Student#1.txt","Student#2.txt"...
string arrStudent1[8];//This array stores student#1, student#2, student#3 grades

int main()
{
    banner(); //calling banner function
    string getSyllabus; //variable to get desire syllabus
    int numStudent; //variable to get desire of number of students
    cout << "Where is the worth of each course part stored? ";
    cin>>getSyllabus;
    cin.ignore();
    validate(getSyllabus);//calling validate function to validate if the syllabus exists
    cout <<"How many students are in your course? (max 3) "; //there are only 3 student files
    cin >>numStudent;
    cin.ignore();
    if(validateStudent(numStudent))//calling validateStudent to see if the file exists
{
    for (int index=1; index <=numStudent; index++) //this for loop will run as many times as the number of students
    {
        //this member function will convert integer to string
        //for example, I want the name to be Student#1.txt but 1 is integer so I converted to string 
        //and combine it together I got Student#1.txt, Student#2.txt, Student#3.txt
          string strStudentfile =to_string(index); 
    arrStudent[index-1]= file2+strStudentfile+file;//Store them into the array
    if(valid(arrStudent[index-1]))//if the file exists by calling the valid function to check 
      {
        if(getSyllabus==Syllabus1) //if the user chose syllabus.txt before
       inputFileofStudent(arrStudent[index-1], sizeSyll1);//calling inputFileofStudent function
                                                          //passing the Student#1.txt, and 1st syllabus size
       else if(getSyllabus==Syllabus2) //if the user chose syllabus2.txt before
        inputFileofStudent(arrStudent[index-1], sizeSyll2);//calling inputFileofStudent function
                                                          //passing the Student#1.txt, and 2nd syllabus size
      }
    }
}
//After everything is done, display the message so the user know where to check 
cout << "Information were written to files. Please check your folder. Press Enter to exit";
cin.get(); //get enter 
return 0;
}
void banner() //header function
{
     cout << "\t\t\t\t\tDescription: This program saves and calculate students' grade. " << endl;
    cout << "\t\t\t\t\tLAB: Final Exam Capstone" << endl; 
    cout << "\t\t\t\t\tCourse: CIT 120-T1"<< endl;
    cout << "\t\t\t\t\tProgrammer: Christina Trinh" << endl;
    cout << "\t\t\t\t\tProfessor: Makhene" << endl;
    cout << "\t\t\t\t\tDate: 5/6/21" << endl;
}
bool valid(string file) //descripted in prototype
{
    ifstream inputFile;
    inputFile.open(file); //attempt to open the file to check
    if(inputFile) //if exists
    return true; //return true
    else  //if doesn't
    return false; //return false
    
}

bool validate(string fileName) //descripted in prototype
{
    bool status = false; //bool variable
    ifstream inputFile;
    do
    {
        inputFile.open(fileName); //open file
        if(inputFile && fileName==Syllabus1)//if file is successully opened and is syllabus1
        {
            //display message
cout <<"I am getting the answer key from "<< Syllabus1<<endl <<"This course has " << sizeSyll1 << " parts\n\n";
       
        for(int count =0; count<sizeSyll1; count++)
       {
           getline(inputFile, fileName, '%'); //Get the whole thing on one line
           arrSyll[count] = fileName+'%'; //store them in the array arrSyll to use later for outputing files
       }
       status=true;//set status to true so it get out of loop 
        }
        else if(inputFile && fileName==Syllabus2)//OR if file is successully opened and is syllabus2
        {
            //message
            cout <<"I am getting the answer key from "<< Syllabus2<<endl <<"This course has " << sizeSyll2 << " parts\n\n";
        
        for(int count =0; count<sizeSyll2; count++)
       {
           getline(inputFile, fileName, '%'); //Get the whole thing on one line
           arrSyll[count] = fileName+'%';//also store them in the array arrSyll 
       }
       status=true; //also set status to true and get out of loop
        }
        else //if file doesn't exist then the loop will continue because status still false
        {
            cout <<"Unable to open the file "<<fileName<< endl <<"Please enter the right file name: ";
            cin>>fileName;
            cin.ignore();
        }
    } while (status==false); //loop will continue until file is found
    inputFile.close(); //then close file
    return status; //return bool
}

bool validateStudent (int number) //descripted
{
    //if the number enter exceeds 3 and is not a number or is not a whole positive number
    //then would coutinue to ask until number is accepted
    while(number<=0 || number >3||cin.fail())
    {
        cout <<"Invalid number of students. Please Enter at least 1 student and maximum of 3 students: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>number;
    }
    return true;
}

void inputFileofStudent (string fileName, int size) //descripted 
{
    ifstream inputFile;
    inputFile.open(fileName); //open file
  for(int count =0; count<8; count++)
       {
        getline(inputFile,fileName, '\n'); //get information from the files Student#1.txt,or Student#2.txt...
           arrStudent1[count] = fileName+'\n'; //store it into the array arrStudent1, the values in array can be 
                                               //change through out the loop
       }
       Loads(size);//after each loop ended(each student file), call Loads function to output information
       inputFile.close(); //close file
}

void Loads (int syllabusSize) //descripted 
{
    double total=0; //variable storing the total grade for each student
    ofstream outputFile;
    string openName;
    outputFile.open(arrStudent1[0]+".txt"); //open file as the name of the student stored in the array
    outputFile << "\t\t\t" << arrStudent1[0]<<endl; //output formatting the name on top 
    for(int count=0; count<syllabusSize; count ++)
    {
        double score=grade(count+1, syllabusSize); //calculate score by calling function grade
                                                //pass the current count and syllabus size so it can calculate
        total+=score; //the toal variable is being added as the loop continue

        //output in the files, formatting, information
    outputFile << arrSyll[count] << "  |  Grade: " <<arrStudent1[count+1] 
                <<"\t\tPercent equivalent: "<< score <<"%" <<endl;
    }
    outputFile << "TOTAL COURSE GRADE: "<<total <<"%" <<endl <<endl;//after loop ended, display total grades
    if(total>=70) //if total is greater than 70 then passed
    outputFile << "STUDENT PASSED! CONGRATULATIONS"; 
    else  //if lower then failed
    outputFile << "STUDENT FAILED! GIVE MORE EFFORTS";
    outputFile.close();//close file
}

double grade(int count, int sylsize) //descripted
{
    double grade=0; //set the grade to zero and using double because they have decimal points
    int num;
    stringstream ss; //using the string stream class to convert from string to integer
    ss <<arrStudent1[count];  //first we put the string value into ss variable that was declared
    
    //then if the information was any grades in the file
    if(count==1||count==2||count==4||count==5||count==6||count ==7)
    ss>> num; //I extract that string to num, which is an integer variable 
    
    if(sylsize==7) //if size is 7(syllabus 1)
    grade = (array1[count-1] *num);//calculate grades
    else if(sylsize==5) //if size is 5(syllabus 2)
    grade = (array2[count-1] *num); //calculate grades(2 are extra credits)
    return grade; //return the grade
}