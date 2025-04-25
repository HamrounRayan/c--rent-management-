#ifndef LOG_LLC_BIBLIO
#define LOG_LLC_BIBLIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ----------- definition of types -----------
typedef struct
{
    char type[10];
    char street[50];
    int surface;
    int distance;
    int id;
} logement;

typedef struct
{
    int logementID;
    int locataireID;
    int startDate;
    int endDate;
} location;

typedef struct
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    int id;
} locataire;

typedef struct
{
    char name[50];
    int frequency;
} nmbrCartier;
//-------------------------------------------------

// ----------- definition of nodes -----------
typedef struct Node_logement
{
    logement data;
    struct Node_logement *Next;
} Node_logement;

typedef struct Node_location
{
    location data;
    struct Node_location *Next;
} Node_location;

typedef struct Node_locataire
{
    locataire data;
    struct Node_locataire *Next;
} Node_locataire;

typedef struct Node_nmbrCartier
{
    nmbrCartier data;
    struct Node_nmbrCartier *Next;
} Node_nmbrCartier;
//-------------------------------------------------

// ----------- Nodes Initialisation -----------
Node_logement *head_logement;
Node_location *head_location;
Node_locataire *head_locataire;
Node_logement *head_archiveLogement;
Node_location *head_archiveLocation;
Node_locataire *head_archiveLocataire;
Node_nmbrCartier *head_nmbrCartier;
Node_logement *head_plpmoc;
//-------------------------------------------------

// ----------- ALLOCATE -----------
void allocate_logement(Node_logement **p)
{
    *p = (Node_logement *)malloc(sizeof(Node_logement));
    (*p)->Next = NULL;
}

void allocate_location(Node_location **p)
{
    *p = (Node_location *)malloc(sizeof(Node_location));
    (*p)->Next = NULL;
}

void allocate_locataire(Node_locataire **p)
{
    *p = (Node_locataire *)malloc(sizeof(Node_locataire));
    (*p)->Next = NULL;
}

void allocate_nmbrCartier(Node_nmbrCartier **p)
{
    *p = (Node_nmbrCartier *)malloc(sizeof(Node_nmbrCartier));
    (*p)->Next = NULL;
}
//-------------------------------------------------

// ----------- NEXT -----------
Node_logement *Next_logement(Node_logement *P) { return P->Next; }
Node_location *Next_location(Node_location *P) { return P->Next; }
Node_locataire *Next_locataire(Node_locataire *P) { return P->Next; }
Node_nmbrCartier *Next_nmbrCartier(Node_nmbrCartier *P) { return P->Next; }
//-------------------------------------------------

// ----------- DATA -----------
logement data_logement(Node_logement *P) { return P->data; }
location data_location(Node_location *P) { return P->data; }
locataire data_locataire(Node_locataire *P) { return P->data; }
nmbrCartier data_nmbrCartier(Node_nmbrCartier *P) { return P->data; }
//-------------------------------------------------

// ----------- FREE -----------
void Free_logement(Node_logement *head)
{
    Node_logement *t;
    while (head)
    {
        t = head->Next;
        free(head);
        head = t;
    }
}

void Free_location(Node_location *head)
{
    Node_location *t;
    while (head)
    {
        t = head->Next;
        free(head);
        head = t;
    }
}

void Free_locataire(Node_locataire *head)
{
    Node_locataire *t;
    while (head)
    {
        t = head->Next;
        free(head);
        head = t;
    }
}

void Free_nmbrCartier(Node_nmbrCartier *head)
{
    Node_nmbrCartier *t;
    while (head)
    {
        t = head->Next;
        free(head);
        head = t;
    }
}
//-------------------------------------------------

// ----------- SET DATA -----------
void setData_logement(Node_logement *p, logement d)
{
    strcpy(p->data.type, d.type);
    strcpy(p->data.street, d.street);
    p->data.surface = d.surface;
    p->data.distance = d.distance;
    p->data.id = d.id;
}

void setData_location(Node_location *p, location d)
{
    p->data.logementID = d.logementID;
    p->data.locataireID = d.locataireID;
    p->data.startDate = d.startDate;
    p->data.endDate = d.endDate;
}

void setData_locataire(Node_locataire *p, locataire d)
{
    strcpy(p->data.firstName, d.firstName);
    strcpy(p->data.lastName, d.lastName);
    strcpy(p->data.phoneNumber, d.phoneNumber);
    p->data.id = d.id;
}

void setData_nmbrCartier(Node_nmbrCartier *p, nmbrCartier d)
{
    strcpy(p->data.name, d.name);
    p->data.frequency = d.frequency;
}
//-------------------------------------------------

// ----------- SET NEXT -----------
void setNEXT_logement(Node_logement *p, Node_logement *q) { p->Next = q; }
void setNEXT_location(Node_location *p, Node_location *q) { p->Next = q; }
void setNEXT_locataire(Node_locataire *p, Node_locataire *q) { p->Next = q; }
void setNEXT_nmbrCartier(Node_nmbrCartier *p, Node_nmbrCartier *q) { p->Next = q; }
//-------------------------------------------------

//-------------------PRINT LIST-------------------
void print_logement(Node_logement *p)
{
    Node_logement *q;
    q = p;
    while (q != NULL)
    {
        printf("%s ", data_logement(q).type);
        printf("%s ", data_logement(q).street);
        printf("%d ", data_logement(q).surface);
        printf("%d ", data_logement(q).distance);
        printf("%d\n", data_logement(q).id);
        q = Next_logement(q);
    }
}

void print_location(Node_location *p)
{
    Node_location *q;
    q = p;
    while (q != NULL)
    {
        printf("%d ", data_location(q).logementID);
        printf("%d ", data_location(q).locataireID);
        printf("%d ", data_location(q).startDate);
        printf("%d \n", data_location(q).endDate);
        q = Next_location(q);
    }
}

void print_locataire(Node_locataire *p)
{
    Node_locataire *q;
    q = p;
    while (q != NULL)
    {
        printf("%s ", data_locataire(q).firstName);
        printf("%s ", data_locataire(q).lastName);
        printf("%s ", data_locataire(q).phoneNumber);
        printf("%d\n", data_locataire(q).id);
        q = Next_locataire(q);
    }
}

void print_nmbrCartier(Node_nmbrCartier *p)
{
    Node_nmbrCartier *q;
    q = p;
    while (q != NULL)
    {
        printf("%s ", data_nmbrCartier(q).name);
        printf("%d\n", data_nmbrCartier(q).frequency);
        q = Next_nmbrCartier(q);
    }
}

void print_maillon_logement(Node_logement *p)
{
    printf("%s ", data_logement(p).type);
    printf("%s ", data_logement(p).street);
    printf("%d ", data_logement(p).surface);
    printf("%d ", data_logement(p).distance);
    printf("%d\n", data_logement(p).id);
}

void print_maillon_location(Node_location *p)
{
    printf("%d ", data_location(p).logementID);
    printf("%d ", data_location(p).locataireID);
    printf("%d ", data_location(p).startDate);
    printf("%d \n", data_location(p).endDate);
}

void print_maillon_locataire(Node_locataire *p)
{
    printf("%s ", data_locataire(p).firstName);
    printf("%s ", data_locataire(p).lastName);
    printf("%s ", data_locataire(p).phoneNumber);
    printf("%d\n", data_locataire(p).id);
}

void print_maillon_nmbrCartier(Node_nmbrCartier *p)
{
    printf("%s ", data_nmbrCartier(p).name);
    printf("%d\n", data_nmbrCartier(p).frequency);
}
//-------------------------------------------------

//----------------------LOYER----------------------
int loyer_logement(Node_logement *p) {
    int temp;
    char type[10];

    strcpy(type, data_logement(p).type); // we convert the type to lowercase
    for(int i = 0; type[i]; i++) {
        type[i] = tolower(type[i]);
    }
    
    //we compare it to the types
    if (strcmp(type, "studio") == 0) {
        temp = 15000 + (data_logement(p).surface - 20) * 800;
    } else if (strcmp(type, "f2") == 0 || strcmp(data_logement(p).type, "F2") == 0) {
        temp = 20000 + (data_logement(p).surface - 45) * 800;
    } else if (strcmp(type, "f3") == 0 || strcmp(data_logement(p).type, "F3") == 0) {
        temp = 30000 + (data_logement(p).surface - 65) * 800;
    } else if (strcmp(type, "f4") == 0 || strcmp(data_logement(p).type, "F4") == 0) {
        temp = 45000 + (data_logement(p).surface - 85) * 800;
    } else {
        printf("Unknown property type: %s\n", data_logement(p).type);
        temp = 0;
    }
    
    return temp;
}
int loyer_location(Node_location *p) {
    int temp = 1;
    Node_logement *q;
    q = head_logement;
    // find the coresponding logement
    while (q != NULL) {
        if (data_logement(q).id == data_location(p).logementID) {
            temp = loyer_logement(q);
            break;
        }
        q = Next_logement(q);
    }
    
    return temp;
}
//-------------------------------------------------

//----------------------Load-----------------------
void loadLogement()
{   //extract the data from the logement file and store it in a linked list
    Node_logement *p;
    p = head_logement;
    FILE *file;
    file = fopen("data files/logements.txt", "r");
    logement temp;
    int first = 1;
    while (fscanf(file, "%s %s %d %d %d", temp.type, temp.street, &temp.surface, &temp.distance, &temp.id) == 5)
    {
        Node_logement *q;
        allocate_logement(&q);
        setData_logement(q, temp);
        if (first)
        {
            head_logement = q;
            first = 0;
        }
        else
        {
            setNEXT_logement(p, q);
        }
        p = q;
    }
    setNEXT_logement(p, NULL);
    fclose(file);
}

void loadLocation()
{   //extract the data from the location file and store it in a linked list
    Node_location *p;
    p = head_location;
    FILE *file;
    file = fopen("data files/locations.txt", "r");
    location temp;
    int first = 1;
    while (fscanf(file, "%d %d %d %d", &temp.logementID, &temp.locataireID, &temp.startDate, &temp.endDate) == 4)
    {
        Node_location *q;
        allocate_location(&q);
        setData_location(q, temp);
        if (first)
        {
            head_location = q;
            first = 0;
        }
        else
        {
            setNEXT_location(p, q);
        }
        p = q;
    }
    setNEXT_location(p, NULL);
    fclose(file);
}

void loadLocataire()
{   //extract the data from the locataire file and store it in a linked list
    Node_locataire *p;
    p = head_locataire;
    FILE *file;
    file = fopen("data files/locataires.txt", "r");
    locataire temp;
    int first = 1;
    while (fscanf(file, "%s %s %s %d", temp.firstName, temp.lastName, temp.phoneNumber, &temp.id) == 4)
    {
        Node_locataire *q;
        allocate_locataire(&q);
        setData_locataire(q, temp);
        if (first)
        {
            head_locataire = q;
            first = 0;
        }
        else
        {
            setNEXT_locataire(p, q);
        }
        p = q;
    }
    setNEXT_locataire(p, NULL);
    fclose(file);
}

void loadArchiveLogement()
{   //extract the data from the archiveLogement file and store it in a linked list
    Node_logement *p;
    p = head_archiveLogement;
    FILE *file;
    file = fopen("data files/archiveLogement", "r");
    logement temp;
    int first = 1;
    while (fscanf(file, "%s %s %d %d %d", temp.type, temp.street, &temp.surface, &temp.distance, &temp.id) == 5)
    {
        Node_logement *q;
        allocate_logement(&q);
        setData_logement(q, temp);
        if (first)
        {
            head_archiveLogement = q;
            first = 0;
        }
        else
        {
            setNEXT_logement(p, q);
        }
        p = q;
    }
    setNEXT_logement(p, NULL);
    fclose(file);
}

void loadArchiveLocation()
{   //extract the data from the archivelocation file and store it in a linked list
    Node_location *p;
    p = head_archiveLocation;
    FILE *file;
    file = fopen("data files/archiveLocation", "r");
    location temp;
    int first = 1;
    while (fscanf(file, "%d %d %d %d", &temp.logementID, &temp.locataireID, &temp.startDate, &temp.endDate) == 4)
    {
        Node_location *q;
        allocate_location(&q);
        setData_location(q, temp);
        if (first)
        {
            head_archiveLocation = q;
            first = 0;
        }
        else
        {
            setNEXT_location(p, q);
        }
        p = q;
    }
    setNEXT_location(p, NULL);
    fclose(file);
}

void loadArchivelocataire()
{   //extract the data from the archiveLocataire file and store it in a linked list
    Node_locataire *p;
    p = head_archiveLocataire;
    FILE *file;
    file = fopen("data files/archiveLocataire", "r");
    locataire temp;
    int first = 1;
    while (fscanf(file, "%s %s %s %d", temp.firstName, temp.lastName, temp.phoneNumber, &temp.id) == 4)
    {
        Node_locataire *q;
        allocate_locataire(&q);
        setData_locataire(q, temp);
        if (first)
        {
            head_archiveLocataire = q;
            first = 0;
        }
        else
        {
            setNEXT_locataire(p, q);
        }
        p = q;
    }
    setNEXT_locataire(p, NULL);
    fclose(file);
}
//-------------------------------------------------

//----------------------SAVE----------------------
void saveLogement()
{   //save the changes done on the linked list to its corresponding text file
    Node_logement *p;
    FILE *file;
    p = head_logement;
    file = fopen("data files/logements.txtt", "w");
    while (p != NULL)
    {
        logement temp;
        temp = data_logement(p);
        fprintf(file, "%s %s %d %d %d\n", temp.type, temp.street, temp.surface, temp.distance, temp.id);
        p = Next_logement(p);
    }
    fclose(file);
}

void saveLocation()
{   //save the changes done on the linked list to its corresponding text file
    Node_location *p;
    FILE *file;
    p = head_location;
    file = fopen("data files/locations.txt", "w");
    while (p != NULL)
    {
        location temp;
        temp = data_location(p);
        fprintf(file, "%d %d %d %d\n", temp.logementID, temp.locataireID, temp.startDate, temp.endDate);
        p = Next_location(p);
    }
    fclose(file);
}

void saveLocataire()
{   //save the changes done on the linked list to its corresponding text file
    Node_locataire *p;
    FILE *file;
    p = head_locataire;
    file = fopen("data files/locataires.txt", "w");
    while (p != NULL)
    {
        locataire temp;
        temp = data_locataire(p);
        fprintf(file, "%s %s %s %d\n", temp.firstName, temp.lastName, temp.phoneNumber, temp.id);
        p = Next_locataire(p);
    }
    fclose(file);
}

void saveArchiveLogement()
{   //save the changes done on the linked list to its corresponding text file
    Node_logement *p;
    FILE *file;
    p = head_archiveLogement;
    file = fopen("data files/archiveLogement", "w");
    while (p != NULL)
    {
        logement temp;
        temp = data_logement(p);
        fprintf(file, "%s %s %d %d %d\n", temp.type, temp.street, temp.surface, temp.distance, temp.id);
        p = Next_logement(p);
    }
    fclose(file);
}

void saveArchiveLocation()
{   //save the changes done on the linked list to its corresponding text file
    Node_location *p;
    FILE *file;
    p = head_archiveLocation;
    file = fopen("data files/archiveLocation", "w");
    while (p != NULL)
    {
        location temp;
        temp = data_location(p);
        fprintf(file, "%d %d %d %d\n", temp.logementID, temp.locataireID, temp.startDate, temp.endDate);
        p = Next_location(p);
    }
    fclose(file);
}

void saveArchivelocataire()
{   //save the changes done on the linked list to its corresponding text file
    Node_locataire *p;
    FILE *file;
    p = head_archiveLocataire;
    file = fopen("data files/archiveLocataire", "w");
    while (p != NULL)
    {
        locataire temp;
        temp = data_locataire(p);
        fprintf(file, "%s %s %s %d\n", temp.firstName, temp.lastName, temp.phoneNumber, temp.id);
        p = Next_locataire(p);
    }
    fclose(file);
}
//-------------------------------------------------

//-----------------------ID------------------------
int id_logement()
{   // generate a new logement id such that it does repeat itself
    int id = 0;
    loadLogement();
    loadArchiveLogement();
    Node_logement *p;
    p = head_logement;
    while (p != NULL)
    {   //it has to be bigger than all ids in logement
        if (data_logement(p).id > id)
        {
            id = data_logement(p).id;
        }
        p = Next_logement(p);
    }
    p = head_archiveLogement;
    while (p != NULL)
    {   //it has to be bigger than all ids in archiveLogement
        if (data_logement(p).id > id)
        {
            id = data_logement(p).id;
        }
        p = Next_logement(p);
    }
    id = id + 1;
    return id;
}
int id_locataire()
{   // generate a new locataire id such that it does repeat itself
    int id = 0;
    loadLocataire();
    loadArchivelocataire();
    Node_locataire *p;
    p = head_locataire;
    while (p != NULL)
    {   //it has to be bigger than all ids in locataire
        if (data_locataire(p).id > id)
        {
            id = data_locataire(p).id;
        }
        p = Next_locataire(p);
    }
    p = head_archiveLocataire;
    while (p != NULL)
    {   //it has to be bigger than all ids in archiveLocataire
        if (data_locataire(p).id > id)
        {
            id = data_locataire(p).id;
        }
        p = Next_locataire(p);
    }
    id = id + 1;
    return id;
}
//-------------------------------------------------

//----------------------ADD-----------------------
void add_Logement()
{   //add a new logement node to the linked list
    logement temp;
    loadLogement();
    printf("Type of logement : \n");
    scanf("%s", temp.type);
    printf("Street of logement : \n");
    scanf("%s", temp.street);
    getchar();
    printf("surface of logement : \n");
    scanf("%d", &temp.surface);
    printf("distance from city : \n");
    scanf("%d", &temp.distance);
    temp.id = id_logement();
    Node_logement *p;
    allocate_logement(&p);
    setData_logement(p, temp);
    setNEXT_logement(p, head_logement);
    head_logement = p;
    saveLogement();
    print_logement(head_logement);
    Free_logement(head_logement);
}

void add_Locataire()
{   //add a new locataire node to the linked list
    loadLocataire();
    locataire temp;
    printf("first name : \n");
    scanf("%s", temp.firstName);
    printf("last name : \n");
    scanf("%s", temp.lastName);
    printf("phone number: \n");
    scanf("%s", temp.phoneNumber);
    temp.id = id_locataire();
    Node_locataire *p;
    allocate_locataire(&p);
    setData_locataire(p, temp);
    setNEXT_locataire(p, head_locataire);
    head_locataire = p;
    saveLocataire();
    print_locataire(head_locataire);
}

void add_Location()
{   //add a new location node to the linked list
    location temp;
    loadLocation();
    printf("ID of the logement : \n");
    scanf("%d", &temp.logementID);
    printf("ID of the locataire : \n");
    scanf("%d", &temp.locataireID);
    printf("the starting date in the form YYYYMMDD : \n");
    scanf("%d", &temp.startDate);
    printf("the end date in the form YYYYMMYY : \n");
    scanf("%d", &temp.endDate);
    Node_location *p;
    allocate_location(&p);
    setData_location(p, temp);
    setNEXT_location(p, head_location);
    head_location = p;
    saveLocation();
    print_location(head_location);
}
//------------------------------------------------

//---------------------DELETE----------------------
void delete_Logement()
{   //we take the id to delete the logement with that exact id
    loadArchiveLogement();
    loadLogement();
    int deleteID;
    printf("please enter the ID of logement to delete : \n");
    scanf("%d", &deleteID);
    Node_logement *p;
    Node_logement *q;
    p = head_logement;
    q = Next_logement(p);
    if (data_logement(head_logement).id == deleteID)
    {
        setNEXT_logement(head_logement, head_archiveLogement);
        head_archiveLogement = head_logement;
        head_logement = q;
    }
    while (q != NULL)
    {
        if (data_logement(q).id == deleteID)
        {
            setNEXT_logement(p, Next_logement(q));
            setNEXT_logement(q, head_archiveLogement);
            head_archiveLogement = q;
            break;
        }
        else
        {
            p = q;
            q = Next_logement(q);
        }
    }
    //seve the changes to the text file
    saveLogement();
    saveArchiveLogement();
}

void delete_Location()
{   // we taire both the id of logement and locataire to know the exact location to delete
    loadLocation();
    loadArchiveLocation();
    int deleteID1;
    int deleteID2;
    printf("please enter the ID of logement of the location to delete : \n");
    scanf("%d", &deleteID1);
    printf("please enter the ID of locataire to delete : \n");
    scanf("%d", &deleteID2);
    Node_location *p;
    Node_location *q;
    p = head_location;
    q = Next_location(p);
    if (data_location(head_location).logementID == deleteID1 && data_location(head_location).locataireID == deleteID2)
    {
        setNEXT_location(head_location, head_archiveLocation);
        head_archiveLocation = head_location;
        head_location = q;
    }
    while (q != NULL)
    {
        if (data_location(q).logementID == deleteID1 && data_location(q).locataireID == deleteID2)
        {
            setNEXT_location(p, Next_location(q));
            setNEXT_location(q, head_archiveLocation);
            head_archiveLocation = q;
            break;
        }
        else
        {
            p = q;
            q = Next_location(q);
        }
    }
    //seve the changes to the text file
    saveLocation();
    saveArchiveLocation();
}

void delete_Locataire()
{   //we take the id to delete the locataire with that exact id
    loadLocataire();
    loadArchivelocataire();
    int deleteID;
    printf("please enter the ID of locataire to delete : \n");
    scanf("%d", &deleteID);
    Node_locataire *p;
    Node_locataire *q;
    p = head_locataire;
    q = Next_locataire(p);
    if (data_locataire(head_locataire).id == deleteID)
    {
        setNEXT_locataire(head_locataire, head_archiveLocataire);
        head_archiveLocataire = head_locataire;
        head_locataire = q;
    }
    while (q != NULL)
    {
        if (data_locataire(q).id == deleteID)
        {
            setNEXT_locataire(p, Next_locataire(q));
            setNEXT_locataire(q, head_archiveLocataire);
            head_archiveLocataire = q;
            break;
        }
        else
        {
            p = q;
            q = Next_locataire(q);
        }
    }
    //seve the changes to the text file
    saveLocataire();
    saveArchivelocataire();
}
//-------------------------------------------------

//-----------------SEARCH BY DATE------------------
void searchByDate()
{
    loadLocation();
    loadLogement();
    int date;
    printf("enter the date \n");// we take the date from the user
    scanf("%d", &date);
    Node_logement *p;
    p = head_logement;
    printf("the logements occupied in this date are : \n");
    while (p != NULL)
    {
        Node_location *q;
        q = head_location;
        while (q != NULL)
        {   //each time we check if the date is between the start and end date 
            if (data_logement(p).id == data_location(q).logementID && date >= data_location(q).startDate && date <= data_location(q).endDate)
            {
                print_maillon_logement(p);
                q = NULL;
            }
            else
                q = Next_location(q);
        }
        p = Next_logement(p);
    }
    printf("the logements not occupied in this date are : \n");
    p = head_logement;
    while (p != NULL)
    {
        Node_location *q;
        q = head_location;
        int found = 0;
        while (q != NULL)
        {   // we check if the date is not between the start and end date 
            if (data_logement(p).id == data_location(q).logementID && date >= data_location(q).startDate && date <= data_location(q).endDate)
            {
                found = 1;
                q = NULL;
            }
            else
                q = Next_location(q);
        }
        if (!found)
        {
            print_maillon_logement(p);
        }
        p = Next_logement(p);
    }
    Free_location(head_location);
    Free_logement(head_logement);
}
//-------------------------------------------------

//----------------------SORT-----------------------
void sortLocation(Node_location **head){
    // we sort the location with respect to their loyer 
    Node_location *p;
    p = *head; 
    while (p != NULL){
        Node_location *q;
        q = Next_location(p);
        while (q != NULL){
            if (loyer_location(p) > loyer_location(q)){
                location temp;
                temp = data_location(p);
                setData_location(p, data_location(q));
                setData_location(q, temp);
            }
            q = Next_location(q);
        }
        p = Next_location(p);
    }
}
//-------------------------------------------------

//----------------LOCATION BY TYPE-----------------
void listLocTypeLog() {
    loadLogement();
    loadLocation();
    
    Node_location *head_F4 = NULL, *tail_F4 = NULL;
    Node_location *head_F3 = NULL, *tail_F3 = NULL;
    Node_location *head_F2 = NULL, *tail_F2 = NULL;
    Node_location *head_studio = NULL, *tail_studio = NULL;
    
    Node_location *p = head_location;
    
    while (p != NULL) {
        Node_location *q;
        Node_logement *r = head_logement;
        
        while (r != NULL && data_logement(r).id != data_location(p).logementID) {
            r = Next_logement(r);
        }
        
        if (r != NULL) {
            allocate_location(&q);
            setData_location(q, data_location(p));
            q->Next = NULL;
            
            if (strcmp(data_logement(r).type, "F4") == 0) {
                if (head_F4 == NULL) {
                    head_F4 = q;
                    tail_F4 = q;
                } else {
                    setNEXT_location(tail_F4, q);
                    tail_F4 = q;
                }
            } else if (strcmp(data_logement(r).type, "F3") == 0) {
                if (head_F3 == NULL) {
                    head_F3 = q;
                    tail_F3 = q;
                } else {
                    setNEXT_location(tail_F3, q);
                    tail_F3 = q;
                }
            } else if (strcmp(data_logement(r).type, "F2") == 0) {
                if (head_F2 == NULL) {
                    head_F2 = q;
                    tail_F2 = q;
                } else {
                    setNEXT_location(tail_F2, q);
                    tail_F2 = q;
                }
            } else if (strcmp(data_logement(r).type, "studio") == 0) {
                if (head_studio == NULL) {
                    head_studio = q;
                    tail_studio = q;
                } else {
                    setNEXT_location(tail_studio, q);
                    tail_studio = q;
                }
            }
        }
        
        p = Next_location(p);
    }
    if (head_F4) sortLocation(&head_F4);
    if (head_F3) sortLocation(&head_F3);
    if (head_F2) sortLocation(&head_F2);
    if (head_studio) sortLocation(&head_studio);
    
    printf("\nLocations F4 logements in order of price:\n");
    printf("ID-LOG  ID-LOC  START-D  END-D\n");
    print_location(head_F4);
    
    printf("\nLocation F3 logements in order of price:\n");
    printf("ID-LOG  ID-LOC  START-D  END-D\n");
    print_location(head_F3);
    
    printf("\nLocation F2 logements in order of price:\n");
    printf("ID-LOG  ID-LOC  START-D  END-D\n");
    print_location(head_F2);
    
    printf("\nLocation Studio logements in order of price:\n");
    printf("ID-LOG  ID-LOC  START-D  END-D\n");
    print_location(head_studio);
}
//-------------------------------------------------

//---------------LOCATAIRE BY TYPE-----------------
void listLocataireTypeLog()
{
    loadLogement();
    loadLocation();
    loadLocataire();

    Node_locataire *head_F4 = NULL, *tail_F4 = NULL;
    Node_locataire *head_F3 = NULL, *tail_F3 = NULL;
    Node_locataire *head_F2 = NULL, *tail_F2 = NULL;
    Node_locataire *head_studio = NULL, *tail_studio = NULL;

    Node_location *p = head_location;

    while (p != NULL)
    {
        Node_logement *r = head_logement;
        Node_locataire *t = head_locataire;

        while (r != NULL && data_logement(r).id != data_location(p).logementID)
        {
            r = Next_logement(r);
        }

        if (r != NULL)
        {
            while (t != NULL && t->data.id != data_location(p).locataireID)
            {
                t = Next_locataire(t);
            }

            if (t != NULL)
            {
                Node_locataire *q;
                allocate_locataire(&q);
                setData_locataire(q, t->data);

                if ((strcmp(r->data.type, "F4") == 0) && (r->data.surface > 85))
                {
                    if (head_F4 == NULL)
                    {
                        head_F4 = tail_F4 = q;
                    }
                    else
                    {
                        setNEXT_locataire(tail_F4, q);
                        tail_F4 = q;
                    }
                }
                else if ((strcmp(r->data.type, "F3") == 0) && (r->data.surface > 65))
                {
                    if (head_F3 == NULL)
                    {
                        head_F3 = tail_F3 = q;
                    }
                    else
                    {
                        setNEXT_locataire(tail_F3, q);
                        tail_F3 = q;
                    }
                }
                else if ((strcmp(r->data.type, "F2") == 0) && (r->data.surface > 45))
                {
                    if (head_F2 == NULL)
                    {
                        head_F2 = tail_F2 = q;
                    }
                    else
                    {
                        setNEXT_locataire(tail_F2, q);
                        tail_F2 = q;
                    }
                }
                else if ((strcmp(r->data.type, "studio") == 0) && (r->data.surface > 20))
                {
                    if (head_studio == NULL)
                    {
                        head_studio = tail_studio = q;
                    }
                    else
                    {
                        setNEXT_locataire(tail_studio, q);
                        tail_studio = q;
                    }
                }
            }
        }
        p = Next_location(p);
    }
    printf("Locataire F4 logements sont : \n");
    print_locataire(head_F4);
    printf("Locataire F3 logements sont : \n");
    print_locataire(head_F3);
    printf("Locataire F2 logements sont : \n");
    print_locataire(head_F2);
    printf("Locataire Studio logements sont : \n");
    print_locataire(head_studio);
}
//-------------------------------------------------

//--------------BEST DEAL LOGEMENT-----------------
void addSmallestToList()
{
    if (head_logement == NULL)
        return;

    Node_logement *current = head_logement;
    Node_logement *prev = NULL;
    Node_logement *smallest = head_logement;
    Node_logement *smallestPrev = NULL;

    while (current != NULL)
    {
        int currentScore = ((current->data.distance) * 10) / 2;
        int smallestScore = ((smallest->data.distance) * 10) / 2;

        if (currentScore < smallestScore)
        {
            smallest = current;
            smallestPrev = prev;
        }
        prev = current;
        current = Next_logement(current);
    }

    if (smallestPrev == NULL)
    {
        head_logement = Next_logement(smallest);
    }
    else
    {
        setNEXT_logement(smallestPrev, Next_logement(smallest));
    }

    setNEXT_logement(smallest, head_plpmoc);
    head_plpmoc = smallest;
}

void searchPlpMoc()
{
    loadLogement();
    head_plpmoc = NULL;

    for (int i = 0; i < 5; i++)
    {
        addSmallestToList();
    }

    printf("Les logements les plus proches avec le loyer minimal sont : \n");
    print_logement(head_plpmoc);
}
//-------------------------------------------------

//---------------HISTORY LOGEMENT------------------
void historyNumCartier()
{
    printf("Please, enter the year:\n");
    int year;
    scanf("%d", &year);

    loadArchiveLocation();
    loadArchiveLogement();

    Node_location *p = head_archiveLocation;

    while (p != NULL)
    {
        if ((p->data.startDate / 10000 <= year) && (p->data.endDate / 10000 >= year))
        {
            Node_logement *q = head_archiveLogement;

            while (q != NULL)
            {
                if (q->data.id == p->data.logementID)
                {
                    Node_nmbrCartier *r = head_nmbrCartier, *prev = NULL;
                    while (r != NULL && strcmp(r->data.name, q->data.street) != 0)
                    {
                        prev = r;
                        r = r->Next;
                    }

                    if (r == NULL)
                    {
                        Node_nmbrCartier *newNode;
                        allocate_nmbrCartier(&newNode);
                        strcpy(newNode->data.name, q->data.street);
                        newNode->data.frequency = 1;
                        newNode->Next = NULL;

                        if (prev == NULL)
                        {
                            head_nmbrCartier = newNode;
                        }
                        else
                        {
                            prev->Next = newNode;
                        }
                    }
                    else
                    {
                        r->data.frequency++;
                    }
                }
                q = q->Next;
            }
        }
        p = p->Next;
    }

    print_nmbrCartier(head_nmbrCartier);
}
//-------------------------------------------------

//---------------HISTORY LOCATION------------------
void historyNumLogement()
{
    printf("please, enter the year:\n");
    int year;
    scanf("%d", &year);
    loadArchiveLogement();
    loadArchiveLocation();

    Node_location *p = head_archiveLocation;
    int studio = 0, F2 = 0, F3 = 0, F4 = 0;
    while (p != NULL)
    {
        Node_location *q;
        Node_logement *r = head_archiveLogement;
        if ((p->data.startDate / 10000 <= year) && (p->data.endDate / 10000 >= year))
        {
            while (r != NULL && data_logement(r).id != data_location(p).logementID)
            {
                r = r->Next;
            }

            if (r != NULL)
            {
                if (strcmp(r->data.type, "F4") == 0)
                {
                    F4++;
                }
                else if (strcmp(r->data.type, "F3") == 0)
                {
                    F3++;
                }
                else if (strcmp(r->data.type, "F2") == 0)
                {
                    F2++;
                }
                else if (strcmp(r->data.type, "studio") == 0)
                {
                    studio++;
                }
            }
        }

        p = p->Next;
    }

    printf("F4: %d\n", F4);
    printf("F3: %d\n", F3);
    printf("F2: %d\n", F2);
    printf("studio: %d\n", studio);
}
//-------------------------------------------------
#endif