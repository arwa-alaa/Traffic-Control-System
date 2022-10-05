#include <iostream>
#define MaxOfCars 3
#define NumOfDrivers 50
#define NumOfFines 20
#define SpeedOfRoad 100
using namespace std;

int Person_Index = 0, Car_Index = 0, Search_Plate_Number;
string Answer, Owner_Name; 

struct Date
{
    int Day, Month, Year;
};

struct Fine
{
    int Car_Speed;
    float Value;
    string Street_Name;
    Date Fine_Date;
    bool isPaid;

};

struct  Drivers_Cars
{
    int Plate_Num , Num_Fines = 0;
    string Model;
    Date Production_Year;
    Fine  MyFine[NumOfFines];
    float Sum_Fines=0;
};

struct Drivers
{
    string Person_Name;
    Date Birthdate;
    long long  License_Num;
    int Car_Num;
    Drivers_Cars MyCar[MaxOfCars];
    float Total_Fines = 0;

}drivers[NumOfDrivers];

void Car_License(int Count_Drives);
void Find_Driver(int Search_Plate_Number, int& Person_Index, int& Car_Index);
void Violation_Recording();
void Search(int Chosen_Number);
void  Pay_Fines();

int main()
{
    int Chosen_Number, Count_Drives = -1 ;

    while(true)
    {
        cout << "\t\t--------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t## MENU ##" << endl << endl;
        cout << "\t\t\t\t(1) Car License " << endl;
        cout << "\t\t\t\t(2) Report A Car " << endl;
        cout << "\t\t\t\t(3) Search for Car " << endl;
        cout << "\t\t\t\t(4) Pay The Fines " << endl;
        cout << "\t\t\t\t(5) Exit " << endl << endl<< "\t\t\t\t  ";
        cin >> Chosen_Number;
    
      if (Chosen_Number == 1)
      {
         while (true)
         {
            Count_Drives++;
            Car_License(Count_Drives);
            cout << endl << "\t\t\t\tAdd Another Person's Data  (yes or no) : ";
            cin >> Answer;

            if (Answer == "no")
                break;
         }

      }

    else if (Chosen_Number == 2)
    {
        while (true)
        {
            Violation_Recording();
            cout << "\t\t\t\tAdd Fine for Another Car  (yes or no) : ";
            cin >> Answer;

            if (Answer == "no")
                break;
        }
    }
    else if (Chosen_Number == 3)
    {
        cout << "\t\t\t\tDO You Want Search Via" << endl;
        cout << "\t\t\t\t (1) Plate Number Of The Car " << endl;
        cout << "\t\t\t\t (2) The Owner Name " << endl << "\t\t\t\t";
        cin >> Chosen_Number;

        Search(Chosen_Number);
    }

    else if (Chosen_Number == 4)
    {
        Pay_Fines();
    }

    else if (Chosen_Number == 5)
    {
        break;
    }
      // In case the user chose number which not in the menu
    else
    {
        cout << "\t\t\t\t Invalid Input (Try Again)" <<endl;
        continue;
    }    
}
    return 0;
}

void Car_License(int Count_Drives)
{
    cout << "\t\t\t\tName : ";
    cin >> drivers[Count_Drives].Person_Name;

    cout << "\t\t\t\tBirthdate  " << endl;
    cout << "\t\t\t\t Day : ";
    cin >> drivers[Count_Drives].Birthdate.Day;

    cout << "\t\t\t\t Month : ";
    cin >> drivers[Count_Drives].Birthdate.Month;

    cout << "\t\t\t\t Year : ";
    cin >> drivers[Count_Drives].Birthdate.Year;

    cout << "\t\t\t\tLicense Number : ";
    cin >> drivers[Count_Drives].License_Num;
    while (true)
    {
        cout << "\t\t\t\tHow Many Cars Do Have ,Sir?  ";
        cin >> drivers[Count_Drives].Car_Num;
        //In case the user enter number of car > 3
        if (drivers[Count_Drives].Car_Num < 4)
            break;
        else
            cout << "\t\t\t\tThe Maximum Number to Own a Car is 3 (Try Again) " << endl;
    }

    for (int i = 0; i < drivers[Count_Drives].Car_Num; i++)
    {
        cout << "\t\t--------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t*** Data For Car Number " << i + 1 << " ***" << endl;

        cout << "\t\t\t\tCar's Plate Number : ";
        cin >> drivers[Count_Drives].MyCar[i].Plate_Num;

        cout << "\t\t\t\tCar's Model : ";
        cin >> drivers[Count_Drives].MyCar[i].Model;

        cout << "\t\t\t\tCar's Production Year : ";
        cin >> drivers[Count_Drives].MyCar[i].Production_Year.Year;

    }
}

void Find_Driver(int Search_Plate_Number, int& Person_Index, int& Car_Index)
{
    int i = 0;
    bool  isEnd = false;

    while (true)
    {
        int j = 0;
        while (j <= MaxOfCars)
        {
            if (Search_Plate_Number == drivers[i].MyCar[j].Plate_Num)
            {
                Person_Index = i;
                Car_Index = j;
                isEnd = true;
                break;
            }
            j++;
        }
        if (isEnd)
            break;
        i++;
    }
}

void Violation_Recording()
{
    int  Count_Fine_Car = 0;

    cout << "\t\t\t\tCar's Plate Number : ";
    cin >> Search_Plate_Number;

    Find_Driver(Search_Plate_Number, Person_Index, Car_Index);

    while (true)
    {
        Count_Fine_Car++;

        cout << "\t\t\t\tSpeed Of The Car : ";
        cin >> drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Car_Speed;

        if (drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Car_Speed > SpeedOfRoad)
        {
            cout << "\t\t\t\tStreet Name : ";
            cin >> drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Street_Name;

            cout << "\t\t\t\tDate of The Violation  " << endl;
            cout << "\t\t\t\t Day : ";
            cin >> drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Fine_Date.Day;

            cout << "\t\t\t\t Month : ";
            cin >> drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Fine_Date.Month;

            cout << "\t\t\t\t Year : ";
            cin >> drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Fine_Date.Year;

            drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Value = 2.00 * (drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Car_Speed - SpeedOfRoad);
            drivers[Person_Index].MyCar[Car_Index].Sum_Fines += drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].Value;
            drivers[Person_Index].MyCar[Car_Index].MyFine[Count_Fine_Car].isPaid = false;

        }

        else
            cout << "\t\t\t\tIt Is Normal Speed and There Is No Violation" << endl;

        drivers[Person_Index].MyCar[Car_Index].Num_Fines = Count_Fine_Car;
        cout << "\t\t--------------------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\tAdd Another Fine for This Car  (yes or no) : ";
        cin >> Answer;

        if (Answer == "no")
            break;
    }
}

void Search(int Chosen_Number)
{
    if (Chosen_Number == 1)
    {
        cout << "\t\t\t\tPlate Number of The Car : ";
        cin >> Search_Plate_Number;
        Find_Driver(Search_Plate_Number, Person_Index, Car_Index);
        
        cout << "\t\t\t\tThe Owner's Name : " << drivers[Person_Index].Person_Name << endl;
        cout << "\t\t\t\tThe Owner's License Number : " << drivers[Person_Index].License_Num << endl;
        cout << "\t\t\t\tThe Owner Has : " << drivers[Person_Index].Car_Num << " Cars" << endl;

        cout << endl << "\t\t\t\t*** Data for Car ***" << endl;
        cout << "\t\t\t\tPlate : " << drivers[Person_Index].MyCar[Car_Index].Plate_Num << endl;
        cout << "\t\t\t\tModel : " << drivers[Person_Index].MyCar[Car_Index].Model << endl;
        cout << "\t\t\t\tProduction Year : " << drivers[Person_Index].MyCar[Car_Index].Production_Year.Year << endl << endl;
        cout << "\t\t\t\tThis Car Has " << drivers[Person_Index].MyCar[Car_Index].Num_Fines << " Fines" << endl;

        for (int j = 1; j <= drivers[Person_Index].MyCar[Car_Index].Num_Fines; j++)
        {
            cout << "\t\t--------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t***Data of Fine Number " << j << " *** " << endl;

            if (drivers[Person_Index].MyCar[Car_Index].MyFine[j].Car_Speed <= SpeedOfRoad)
            {
                cout << "\t\t\t\tIt Is Normal Speed and There Is No Violation" << endl;
                continue;
            }

            if (drivers[Person_Index].MyCar[Car_Index].MyFine[j].isPaid)
            {
                cout << "\t\t\t\tThe Cost Of The Fine :  0 $ " << endl;
                cout << "\t\t\t\tThe Status of The Fine : Was Paid " << endl;
                drivers[Person_Index].MyCar[Car_Index].Sum_Fines += drivers[Person_Index].MyCar[Car_Index].MyFine[j].Value;
            }
            else if (!drivers[Person_Index].MyCar[Car_Index].MyFine[j].isPaid)
            {
                cout << "\t\t\t\tThe Cost Of The Fine : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Value << " $ " << endl;
                cout << "\t\t\t\tThe Status of The Fine : Wasn't Paid " << endl;
            }
        }
        cout << "\t\t--------------------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\tTotal The Cost of All Fines for This Car =  " << drivers[Person_Index].MyCar[Car_Index].Sum_Fines << " $ " << endl << endl;


        for (int i = 0; i < drivers[Person_Index].Car_Num; i++)
        {
            drivers[Person_Index].Total_Fines += drivers[Person_Index].MyCar[i].Sum_Fines;
        }
        cout << "\t\t\t\tTotal The Cost of All Fines for The Owner =  ";
        cout << drivers[Person_Index].Total_Fines << " $ " << endl << endl;
        drivers[Person_Index].Total_Fines = 0;
    }

    else if (Chosen_Number == 2)
    {
        cout << "\t\t\t\tThe Owner Name : ";
        cin >> Owner_Name;

        int l = 0;
        // this bool in case the while loop end
        bool  isEnd = false;
        while (true)
        {
                if (Owner_Name == drivers[l].Person_Name)
                {
                    Person_Index = l;
                    isEnd = true;
                    break;
                }
            if (isEnd)
                break;
            l++;
        }

        cout << "\t\t\t\tThe Owner's License Number : " << drivers[Person_Index].License_Num << endl;
        cout << "\t\t\t\tThe Owner Has : " << drivers[Person_Index].Car_Num << " Cars" << endl;

        for (int i = 0; i < drivers[Person_Index].Car_Num; i++)
        {
            cout << "\t\t--------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t***Data for Car Number " << i + 1 << " ***" << endl;
            cout << "\t\t\t\tPlate : " << drivers[Person_Index].MyCar[i].Plate_Num << endl;
            cout << "\t\t\t\tModel : " << drivers[Person_Index].MyCar[i].Model << endl;
            cout << "\t\t\t\tProduction Year : " << drivers[Person_Index].MyCar[i].Production_Year.Year << endl << endl;
            cout << "\t\t\t\tThis Car Has " << drivers[Person_Index].MyCar[i].Num_Fines << " Fines" << endl;

            for (int j = 1; j <= drivers[Person_Index].MyCar[i].Num_Fines; j++)
            {
                cout << "\t\t--------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t***Data Of Fine Number " << j << " ***" << endl;

                if (drivers[Person_Index].MyCar[i].MyFine[j].Car_Speed <= SpeedOfRoad)
                {
                    cout << "\t\t\t\tIt Is Normal Speed and There Is No Violation" << endl;
                    continue;
                }

                if (drivers[Person_Index].MyCar[i].MyFine[j].isPaid)
                {
                    cout << "\t\t\t\tThe Cost of The Fine : 0 $ " << endl;
                    cout << "\t\t\t\tThe Status of The Fine : Was Paid " << endl;
                    drivers[Person_Index].MyCar[i].Sum_Fines += drivers[Person_Index].MyCar[i].MyFine[j].Value;
                }

                else if (!drivers[Person_Index].MyCar[i].MyFine[j].isPaid)
                {
                    cout << "\t\t\t\tThe Cost of The Fine : " << drivers[Person_Index].MyCar[i].MyFine[j].Value << " $ " << endl;
                    cout << "\t\t\t\tThe Status of The Fine : Wasn't Paid " << endl;
                }
            }

            cout << "\t\t--------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tTotal The Cost of All Fines  for This Car =  " << drivers[Person_Index].MyCar[i].Sum_Fines << " $ " << endl << endl;

            drivers[Person_Index].Total_Fines += drivers[Person_Index].MyCar[i].Sum_Fines;
        }

        cout << "\t\t\t\tTotal The Cost of All Fines for The Owner =  ";
        cout << drivers[Person_Index].Total_Fines << " $ " << endl << endl;
        drivers[Person_Index].Total_Fines = 0;
    }
}

void  Pay_Fines()
{
    cout << "\t\t\t\tName : ";
    cin >> Owner_Name;

    cout << "\t\t\t\tThe Owner's License Number : ";
    cin >> drivers[Person_Index].License_Num ;

    cout << "\t\t\t\tCar's Plate : ";
    cin >> Search_Plate_Number;

    Find_Driver(Search_Plate_Number, Person_Index, Car_Index);
 
    cout << "\t\t\t\tModel : " << drivers[Person_Index].MyCar[Car_Index].Model << endl;
    cout << "\t\t\t\tProduction Year : " << drivers[Person_Index].MyCar[Car_Index].Production_Year.Year << endl;

    for (int j = 1; j <= drivers[Person_Index].MyCar[Car_Index].Num_Fines; j++)
    {
        cout << "\t\t--------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t***Data of Fine Number " << j << " ***" << endl << endl;

        if (drivers[Person_Index].MyCar[Car_Index].MyFine[j].Car_Speed <= SpeedOfRoad)
        {
            cout << "\t\t\t\tIt Is Normal Speed , Car Doesn't Has Fines" << endl;
            continue;
        }
        cout << "\t\t\t\tDate Of The Violation  " << endl;
        cout << "\t\t\t\t Day : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Fine_Date.Day << endl;
        cout << "\t\t\t\t Month : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Fine_Date.Month << endl;
        cout << "\t\t\t\t Year : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Fine_Date.Year << endl;
        cout << "\t\t\t\tStreet Name : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Street_Name << endl;
        cout << "\t\t\t\tSpeed Of Car : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Car_Speed << endl;
        cout << "\t\t\t\tThe Cost Of The Fine : " << drivers[Person_Index].MyCar[Car_Index].MyFine[j].Value << " $ " << endl;

        cout << "\t\t\t\tPay The Fine (yes or no) : ";
        cin >> Answer;

        if (Answer == "yes")
        {
            drivers[Person_Index].MyCar[Car_Index].MyFine[j].isPaid = true;
            drivers[Person_Index].MyCar[Car_Index].MyFine[j].Value *= -1;
        }
    }
}