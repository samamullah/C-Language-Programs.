#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
// all define values
#define MAX_YEAR  9999
#define MIN_YEAR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "PatientRecordSystem.bin"
#define MAX_FATHER_NAME 50
#define MAX_PATIENT_NAME 50
#define MAX_PATIENT_ADDRESS 300
#define MAX_PATIENT_DISEASE 300
#define MAX_DEPARTMENT_NAME 100
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
//Elements of structure
typedef struct// to call in program
{
    unsigned int patientRecordId; // declare the integer data type
    float patientTotalFees;
    float patientDepositMoney;
    Date patientAdmitDate;// declare the integer data type
    char patientFatherName[MAX_FATHER_NAME];// declare the character array for patient father name
    char patientName[MAX_PATIENT_NAME];// declare the character array for the name
    char patientAddress[MAX_PATIENT_ADDRESS];// declare the character array for the address
    char patientDisease[MAX_PATIENT_DISEASE];// declare the character array for disease
} s_PatientInfo;
//Own version of fgetsRemovedNewLine
void fgetsRemovedNewLine(char * restrict buf, int n,FILE * restrict stream)
{
    if (fgets(buf, n, stream) == NULL)
    {
        printf("Fail to read the input stream");
    }
    else
    {
        buf[strcspn(buf, "\n")] = '\0';
    }
}
//Align the message
void printMessageCenter(const char* message)
{
    int lenght =0;
    int  weight = 0;
    //calculate how many space need to print
    //  len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(weight =0 ; weight < lenght ; weight++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
//Head message
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Patient Record Management System Project        ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
//Display message
void welcomeMessage()
{
    // headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =              Patient Record               =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}
//Validate name
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    //  len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YEAR ||
        validDate->yyyy < MIN_YEAR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
        validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
// Add patient in list
void addPatientInDataBase()
{
    s_PatientInfo addPatientInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW PATIENT");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tPatient ID  = ");
    fflush(stdin);
    scanf("%u",&addPatientInfoInDataBase.patientRecordId);
    do
    {
        printf("\n\t\t\tPatient Father Name  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPatientInfoInDataBase.patientFatherName,MAX_FATHER_NAME,stdin);
        status = isNameValid(addPatientInfoInDataBase.patientFatherName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPatient Name  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPatientInfoInDataBase.patientName,MAX_PATIENT_NAME,stdin);
        status = isNameValid(addPatientInfoInDataBase.patientName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPatient Address  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPatientInfoInDataBase.patientAddress,MAX_FATHER_NAME,stdin);
        status = isNameValid(addPatientInfoInDataBase.patientAddress);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPatient Disease  = ");
        fflush(stdin);
        fgetsRemovedNewLine(addPatientInfoInDataBase.patientDisease,MAX_PATIENT_DISEASE,stdin);
        status = isNameValid(addPatientInfoInDataBase.patientDisease);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    printf("\n\t\t\tPatient Total Charge  = ");
    fflush(stdin);
    scanf("%f",&addPatientInfoInDataBase.patientTotalFees);
    printf("\n\t\t\tPatient Initial Deposit  = ");
    fflush(stdin);
    scanf("%f",&addPatientInfoInDataBase.patientDepositMoney);
    do
    {
        printf("\n\t\t\tPatient Admit Date:- ");
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&addPatientInfoInDataBase.patientAdmitDate.dd,&addPatientInfoInDataBase.patientAdmitDate.mm,&addPatientInfoInDataBase.patientAdmitDate.yyyy);
        //check date validity
        status = isValidDate(&addPatientInfoInDataBase.patientAdmitDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addPatientInfoInDataBase,sizeof(addPatientInfoInDataBase), 1, fp);
    fclose(fp);
}
// search patient Record
void searchPatient()
{
    int found = 0;
    int patientId =0;
    s_PatientInfo addPatientInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH PATIENT");
    //put the control on patient detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter patient  ID NO to search:");
    fflush(stdin);
    scanf("%u",&patientId);
    while (fread (&addPatientInfoInDataBase, sizeof(addPatientInfoInDataBase), 1, fp))
    {
        if(addPatientInfoInDataBase.patientRecordId == patientId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        float remainingAmount = (addPatientInfoInDataBase.patientTotalFees >= addPatientInfoInDataBase.patientDepositMoney)?
        (addPatientInfoInDataBase.patientTotalFees - addPatientInfoInDataBase.patientDepositMoney):(float)(0.0);
        printf("\n\t\t\tPatient id = %d\n",addPatientInfoInDataBase.patientRecordId);
        printf("\n\t\t\tPatient name = %s\n",addPatientInfoInDataBase.patientName);
        printf("\n\t\t\tPatient Disease = %s\n",addPatientInfoInDataBase.patientDisease);
        printf("\t\t\tPatient Total Charge = %f\n",addPatientInfoInDataBase.patientTotalFees);
        printf("\t\t\tPatient Deposit Amount = %f\n",addPatientInfoInDataBase.patientDepositMoney);
        printf("\t\t\tPatient Remaining Amount = %f\n",remainingAmount);
        printf("\t\t\tPatient Father Name = %s\n",addPatientInfoInDataBase.patientFatherName);
        printf("\t\t\tPatient Address = %s\n",addPatientInfoInDataBase.patientAddress);
        printf("\t\t\tPatient Admited Date(day/month/year) =  (%d/%d/%d)\n",addPatientInfoInDataBase.patientAdmitDate.dd,
               addPatientInfoInDataBase.patientAdmitDate.mm, addPatientInfoInDataBase.patientAdmitDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// view Patient function
void viewPatient()
{
    int found = 0;
    s_PatientInfo addPatientInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countPatient = 1;
    headMessage("VIEW PATIENT DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    //Print patient  count
    printf("\n\t\t\tPatient Count = %d\n\n",countPatient);
    while (fread (&addPatientInfoInDataBase, sizeof(addPatientInfoInDataBase), 1, fp))
    {
        float remainingAmount = (addPatientInfoInDataBase.patientTotalFees >= addPatientInfoInDataBase.patientDepositMoney)?
        (addPatientInfoInDataBase.patientTotalFees - addPatientInfoInDataBase.patientDepositMoney):(float)(0.0);
        printf("\t\t\tPatient id = %u\n",addPatientInfoInDataBase.patientRecordId);
        printf("\t\t\tPatient Name = %s\n",addPatientInfoInDataBase.patientName);
        printf("\n\t\t\tPatient Disease = %s\n",addPatientInfoInDataBase.patientDisease);
        printf("\t\t\tPatient Total Charge = %f\n",addPatientInfoInDataBase.patientTotalFees);
        printf("\t\t\tPatient Deposit Amount = %f\n",addPatientInfoInDataBase.patientDepositMoney);
        printf("\t\t\tPatient Remaining Amount = %f\n",remainingAmount);
        printf("\t\t\tPatient Father Name = %s\n",addPatientInfoInDataBase.patientFatherName);
        printf("\t\t\tPatient Address = %s\n",addPatientInfoInDataBase.patientAddress);
        printf("\t\t\tPatient Admited Date(day/month/year) =  (%d/%d/%d)\n\n",addPatientInfoInDataBase.patientAdmitDate.dd,
               addPatientInfoInDataBase.patientAdmitDate.mm, addPatientInfoInDataBase.patientAdmitDate.yyyy);
        found = 1;
        ++countPatient;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// Delete patient Record entry
void deletePatient()
{
    int found = 0;
    int patientDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_PatientInfo addPatientInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete patient Record Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter patient ID NO. for delete:");
    scanf("%d",&patientDelete);
    while (fread (&addPatientInfoInDataBase, sizeof(addPatientInfoInDataBase), 1, fp))
    {
        if(addPatientInfoInDataBase.patientRecordId != patientDelete)
        {
            fwrite(&addPatientInfoInDataBase,sizeof(addPatientInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
//function to update credential
void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    char userName[MAX_SIZE_USER_NAME] = {0};
    char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgetsRemovedNewLine(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgetsRemovedNewLine(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\tRe-Run Application and Login with new Credential:");
    fflush(stdin);
    getchar();
    exit(1);
}
//Display menu
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add New Patient Record");
        printf("\n\t\t\t2.Search Patient Record");
        printf("\n\t\t\t3.View Patient Record");
        printf("\n\t\t\t4.Delete Patient Record");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addPatientInDataBase();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                viewPatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                updateCredential();
                break;
            case 0:
                printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
                exit(1);
                break;
            default:
                printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
//login password
void login()
{
    char userName[MAX_SIZE_USER_NAME] = {0};
    char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("Data base is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgetsRemovedNewLine(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgetsRemovedNewLine(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getchar();
        system("cls");
    }
}
//Check file exist or not
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="aticleworld";
    const char defaultPassword[] ="aticleworld";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
int main()
{
    init();
    welcomeMessage();
    //
    //  login();
    return 0;
}
