#include "allClasses.h"

using namespace std;

//##################  Animal ##################
Animal:: Animal(){
    this->m_color = new char[5];
    strcpy(this->m_color,"GRAY");
    m_avgLifetime = 0;
    m_childCount = 0;
}

Animal:: Animal( const char* color, int childs, float avgLifetime ): m_childCount(childs), m_avgLifetime(avgLifetime){
    m_color = new char[strlen(color) + 1];
    strcpy(m_color,color);
}

Animal:: Animal( ifstream& in_file ){

}

Animal:: Animal(Animal& animal): m_avgLifetime(animal.m_avgLifetime),m_childCount(animal.m_childCount){
    m_color = new char[strlen(animal.m_color) + 1];
    strcpy(this->m_color,animal.m_color);
}

Animal:: ~Animal(){
    //if(this->m_color)
    //    delete[] m_color;
}

const char* Animal:: GetColor() const { return m_color;       }

int	Animal:: GetChildCount() const    { return m_childCount;  }

float Animal:: GetLifetime() const    { return m_avgLifetime; }

//##################  Mammal ##################

Mammals:: Mammals(): Animal(){
    m_pregnancyTime = 0;
    m_milkLiters = 0;
}

Mammals:: Mammals(const char* color, int childs, float avgLifetime, float preg, float milk )
:Animal(color,childs,avgLifetime){
    m_pregnancyTime = preg;
    m_milkLiters = milk;
}

Mammals:: Mammals( ifstream& in_file ){

}

Mammals:: ~Mammals(){
    //nothing to delete.
}

float Mammals:: GetPregnanceTime() const    {    return m_pregnancyTime; }

float Mammals:: GetMilk() const             {    return m_milkLiters;    }

//##################  Birds ##################

Birds:: Birds(): Animal(){
    m_incubationTime = 0;
}

Birds:: Birds( const char* color, int childs, float avgLifetime, float incubation ): Animal(color,childs,avgLifetime){
    m_incubationTime = incubation;
}

Birds:: Birds( ifstream& in_file ) {

}

Birds:: ~Birds(){
    //nothing to delete.
}

float Birds:: GetIncubationTime() const{    return m_incubationTime;    }

//##################  Fish ##################

Fish:: Fish(): Animal(){
    m_finCount = 0;
    m_gillsCount = 0;
}

Fish:: Fish( const char* color, int childs, float avgLifetime, int fin, int gills ): Animal(color,childs,avgLifetime){
    m_finCount = fin;
    m_gillsCount = gills;
}

Fish:: Fish( ifstream& in_file ){

}

Fish:: ~Fish(){
    //nothing to delete.
}

int Fish:: GetFinCount() const      {   return m_finCount;      }

int	Fish:: GetGillsCount() const    {   return m_gillsCount;    }

//##################  Horse ##################

Horse:: Horse(): Mammals(){
    m_type = nullptr;
}

Horse:: Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type )
: Animal(color,childs,avgLifetime){
    m_pregnancyTime = preg;
    m_type = new char[strlen(type) + 1];
    strcpy(m_type,type);
    m_milkLiters = milk;
}

Horse:: Horse( ifstream& in_file ){

}

Horse:: ~Horse(){
    //if(m_type)
    //    delete[] m_type;
}

ofstream& operator << (ofstream& out,const Horse* M){
    out << M->GetColor() << endl;
    out << M->GetChildCount() << endl;
    out << M->GetLifetime() << endl;
    out << M->GetPregnanceTime() << endl;
    out << M->GetMilk() << endl;
    out << M->GetType() << endl;
    return out;
}

const char* Horse:: GetType() const{  return m_type;  }

void Horse:: OutHorse(ostream& out){
    out << this->GetColor() << endl;
    out << this->GetChildCount() << endl;
    out << this->GetLifetime() << endl;
    out << this->GetPregnanceTime() << endl;
    out << this->GetMilk() << endl;
    out << this->GetType() << endl;
}

//##################  Flamingo ##################

Flamingo:: Flamingo(): Birds(){
    m_avgHeight = 0;
}

Flamingo:: Flamingo( const char* color, int childs, float avgLifetime, float incubation, float avgHeight )
: Birds(color,childs,avgHeight,incubation){
    this->m_avgLifetime = avgLifetime;
    m_avgHeight = avgHeight;
}

Flamingo:: Flamingo( ifstream& in_file ){

}

Flamingo:: ~Flamingo(){
    //nothing to delete here.
}

float Flamingo:: GetHeight() const{ return m_avgHeight; }

ofstream& operator << (ofstream& out,const Flamingo& M){
    out << M.GetColor() << endl;
    out << M.GetChildCount() << endl;
    out << M.GetLifetime() << endl;
    out << M.GetIncubationTime() << endl;
    out << M.GetHeight() << endl;
    return out;
}

//##################  MammalsFish ##################

MammalsFish:: MammalsFish(): Mammals(), Fish(){}

MammalsFish:: MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills )
: Animal(color,childs,avgLifetime){
    this->m_pregnancyTime = preg;
    this->m_milkLiters = milk;
    this->m_finCount = fin;
    this->m_gillsCount = gills;
}

MammalsFish:: MammalsFish( ifstream& in_file ){

}

MammalsFish:: ~MammalsFish(){
    //nothing to delete here.
}

//##################  GoldFish ##################

GoldFish:: GoldFish():MammalsFish(){
    m_avgLength = 0;
    m_avgWeight = 0;
}

GoldFish:: GoldFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL )
:Animal(color,childs,avgLifetime){
    this->m_pregnancyTime = preg;
    this->m_milkLiters = milk;
    this->m_finCount = fin;
    this->m_gillsCount = gills;
    m_avgWeight = avgW;
    m_avgLength = avgL;
}

GoldFish:: GoldFish( ifstream& in_file ){

}

GoldFish::  ~GoldFish(){
    //nothing to delete here.
}

float GoldFish:: GetWeight() const{     return this->m_avgWeight;   }

float GoldFish:: GetLength() const{     return this->m_avgLength;   }

ofstream& operator << (ofstream& out,const GoldFish& z){
    out << z.GetColor() << endl;
    out << z.GetChildCount() << endl;
    out << z.GetLifetime() << endl;
    out << z.GetPregnanceTime() << endl;
    out << z.GetMilk() << endl;
    out << z.GetFinCount() << endl;
    out << z.GetGillsCount() << endl;
    out << z.GetWeight() << endl;
    out << z.GetLength() << endl;
    return out;
}

//##################  Mermaid ##################

Mermaid:: Mermaid(): MammalsFish(){
    this->m_firstName = nullptr;
    this->m_lastName = nullptr;
}

Mermaid:: Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName )
: MammalsFish(color,childs,avgLifetime,preg,milk,fin,gills),Animal(color,childs,avgLifetime){
    this->m_firstName = new char[strlen(firstName) + 1];
    strcpy(this->m_firstName,firstName);
    this->m_lastName = new char[strlen(lastName) + 1];
    strcpy(this->m_lastName,lastName);
}

Mermaid:: Mermaid( ifstream& in_file ){

}

Mermaid::  ~Mermaid(){
//    if(this->m_firstName)
//        delete[] this->m_firstName;
//    if(this->m_lastName)
//        delete[] this->m_lastName;
}

const char* Mermaid:: GetFirstName() const{     return this->m_firstName;   }

const char*	Mermaid:: GetLastName() const {     return this->m_lastName;    }

ofstream& operator << (ofstream& out,const Mermaid& z){
    out << z.GetColor() << endl;
    out << z.GetChildCount() << endl;
    out << z.GetLifetime() << endl;
    out << z.GetPregnanceTime() << endl;
    out << z.GetMilk() << endl;
    out << z.GetFinCount() << endl;
    out << z.GetGillsCount() << endl;
    out << z.GetFirstName() << endl;
    out << z.GetLastName() << endl;
    return out;
}

//##################  Zoo ##################

Zoo:: Zoo(){
    this->m_animals = nullptr;
    this->m_name = nullptr;
    this->m_address = nullptr;
    this->m_openHours = nullptr;
    this->m_closeHours = nullptr;
    this->m_ticketPrice = 0;
    this->m_numOfAnimals = 0;
}

Zoo:: Zoo( const char* name, const char* address, float ticket, const char* open, const char* close ){
    this->m_animals = nullptr;
    this->m_numOfAnimals = 0;
    this->m_ticketPrice = ticket;
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name,name);
    this->m_address = new char[strlen(address) +1];
    strcpy(this->m_address,address);
    this->m_openHours = new char[strlen(open) +1];
    strcpy(this->m_openHours,open);
    this->m_closeHours =  new char[strlen(close) +1];
    strcpy(this->m_closeHours,close);
}

Zoo:: Zoo( ifstream& in_file ) {
    in_file.read((char*)this,sizeof(Zoo));
}

Zoo:: ~Zoo(){

}

const char* Zoo:: GetName() const     { return this->m_name;        }

const char*	Zoo:: GetAddress() const  { return this->m_address;     }

float Zoo:: GetTicketPrice() const    { return this->m_ticketPrice; }

const char*	Zoo:: GetOpenHour() const { return this->m_openHours;   }

const char*	Zoo:: GetCloseHour() const{ return this->m_closeHours;  }

int	Zoo:: GetNumOfAnimals() const     { return this->m_numOfAnimals;}

Animal** Zoo:: GetAnimals() const     { return this->m_animals;     }

void Zoo:: AddAnimal( Animal* an ){
    if(typeid(*an) == typeid(Horse))
        AddHorse(dynamic_cast<Horse*>(an));
    if(typeid(*an) == typeid(GoldFish))
        AddGoldFish(dynamic_cast<GoldFish*>(an));
    if(typeid(*an) == typeid(Mermaid))
        AddMermaid(dynamic_cast<Mermaid*>(an));
    if(typeid(*an) == typeid(Flamingo))
        AddFlamingo(dynamic_cast<Flamingo*>(an));
}

void Zoo:: AddHorse(Horse* an){
    Horse* newAnimal = new Horse(an->GetColor(),an->GetChildCount(),an->GetLifetime(),an->GetPregnanceTime(),an->GetMilk(),an->GetType());
    if(!this->m_animals) {
        this->m_animals = new Animal *[1];
        this->m_animals[0] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
    }   else    {
        Animal** tmp = new Animal*[this->m_numOfAnimals + 1];
        for(int i = 0; i < this->m_numOfAnimals; i++){
            tmp[i] = this->m_animals[i];
        }
        tmp[this->m_numOfAnimals] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
        for(int i = 0; i < this->m_numOfAnimals; i++){
            this->m_animals[i] = tmp[i];
        }
    }
}

void Zoo:: AddGoldFish(GoldFish* an){
    GoldFish* newAnimal = new GoldFish(an->GetColor(),an->GetChildCount(),an->GetLifetime(),an->GetPregnanceTime(),an->GetMilk(),an->GetFinCount(),an->GetGillsCount(),an->GetWeight(),an->GetLength());
    if(!this->m_animals) {
        this->m_animals = new Animal *[1];
        this->m_animals[0] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
    }   else    {
        Animal** tmp = new Animal*[this->m_numOfAnimals + 1];
        for(int i = 0; i < this->m_numOfAnimals; i++){
            tmp[i] = this->m_animals[i];
        }
        tmp[this->m_numOfAnimals] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
        for(int i = 0; i < this->m_numOfAnimals; i++){
            this->m_animals[i] = tmp[i];
        }
    }
}

void Zoo:: AddMermaid(Mermaid* an){
    Mermaid* newAnimal = new Mermaid(an->GetColor(),an->GetChildCount(),an->GetLifetime(),an->GetPregnanceTime(),an->GetMilk(),an->GetFinCount(),an->GetGillsCount(),an->GetFirstName(),an->GetLastName());
    if(!this->m_animals) {
        this->m_animals = new Animal *[1];
        this->m_animals[0] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
    }   else    {
        Animal** tmp = new Animal*[this->m_numOfAnimals + 1];
        for(int i = 0; i < this->m_numOfAnimals; i++){
            tmp[i] = this->m_animals[i];
        }
        tmp[this->m_numOfAnimals] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
        for(int i = 0; i < this->m_numOfAnimals; i++){
            this->m_animals[i] = tmp[i];
        }
    }
}

void Zoo:: AddFlamingo(Flamingo* an){
    Flamingo* newAnimal = new Flamingo(an->GetColor(),an->GetChildCount(),an->GetLifetime(),an->GetIncubationTime(),an->GetHeight());
    if(!this->m_animals) {
        this->m_animals = new Animal *[1];
        this->m_animals[0] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
    }   else    {
        Animal** tmp = new Animal*[this->m_numOfAnimals + 1];
        for(int i = 0; i < this->m_numOfAnimals; i++){
            tmp[i] = this->m_animals[i];
        }
        tmp[this->m_numOfAnimals] = newAnimal;
        this->m_numOfAnimals++; //resize the number of animals.
        for(int i = 0; i < this->m_numOfAnimals; i++){
            this->m_animals[i] = tmp[i];
        }
    }
}

void Zoo:: OutHorse(ofstream& out, Horse* m) const{
    out << "Ho" << endl;
    out << strlen(m->GetColor()) << endl;
    out << m->GetColor() << endl;
    out << m->GetChildCount() << endl;
    out << m->GetLifetime() << endl;
    out << m->GetPregnanceTime() << endl;
    out << m->GetMilk() << endl;
    out << strlen(m->GetType()) << endl;
    out << m->GetType() << endl;
}

void Zoo:: OutGoldFish(ofstream& out, GoldFish* m) const{
    out << "Go" << endl;
    out << strlen(m->GetColor()) << endl;
    out << m->GetColor() << endl;
    out << m->GetChildCount() << endl;
    out << m->GetLifetime() << endl;
    out << m->GetPregnanceTime() << endl;
    out << m->GetMilk() << endl;
    out << m->GetFinCount() << endl;
    out << m->GetGillsCount() << endl;
    out << m->GetWeight() << endl;
    out << m->GetLength() << endl;
}

void Zoo:: OutMermaid(ofstream& out, Mermaid* m) const{
    out << "Me" << endl;
    out << strlen(m->GetColor()) << endl;
    out << m->GetColor() << endl;
    out << m->GetChildCount() << endl;
    out << m->GetLifetime() << endl;
    out << m->GetPregnanceTime() << endl;
    out << m->GetMilk() << endl;
    out << m->GetFinCount() << endl;
    out << m->GetGillsCount() << endl;
    out << strlen(m->GetFirstName()) << endl;
    out << m->GetFirstName() << endl;
    out << strlen(m->GetLastName()) << endl;
    out << m->GetLastName() << endl;
}

void Zoo:: OutFlamingo(ofstream& out, Flamingo* m) const{
    out << "Fl" << endl;
    out << strlen(m->GetColor()) << endl;
    out << m->GetColor() << endl;
    out << m->GetChildCount() << endl;
    out << m->GetLifetime() << endl;
    out << m->GetIncubationTime() << endl;
    out << m->GetHeight() << endl;
}

Zoo& Zoo:: operator+( Animal* an ) {
    Animal **tmp = new Animal *[this->m_numOfAnimals + 1];
    for (int i = 0; i < this->m_numOfAnimals; i++) {
        tmp[i] = this->m_animals[i];
    }
    tmp[this->m_numOfAnimals] = an;
    this->m_numOfAnimals++; //resize the number of animals
    this->m_animals = new Animal *[this->m_numOfAnimals];
    for (int i = 0; i < this->m_numOfAnimals; i++) {
        this->m_animals[i] = tmp[i];
    }
    return *this;
}

Zoo Zoo:: operator+( const Zoo& other ) const{
    Zoo* newZoo = new Zoo(this->GetName(),this->GetAddress(),this->GetTicketPrice(),this->m_openHours,this->m_closeHours);
    newZoo->m_numOfAnimals = this->m_numOfAnimals + other.m_numOfAnimals;
    newZoo->m_animals = new Animal*[newZoo->m_numOfAnimals];
    for(int i = 0; i < newZoo->m_numOfAnimals; i++){
        if(i < this->m_numOfAnimals){
            newZoo->m_animals[i] = this->m_animals[i];
        }   else    {
            newZoo->m_animals[i] = other.m_animals[i - this->m_numOfAnimals];
        }
    }
    return *newZoo;
}

Zoo& Zoo:: operator+=(Animal* an){
    AddAnimal(an);
    return *this;
}

ofstream& operator<<( ofstream& out, const Zoo& z ){
    //output the animals information.
    out << strlen(z.GetName()) << endl;
    out << z.GetName() << endl;
    out << strlen(z.GetAddress()) << endl;
    out << z.GetAddress() << endl;
    out << z.GetTicketPrice() << endl;
    out << strlen(z.GetOpenHour()) << endl;
    out << z.GetOpenHour() << endl;
    out << strlen(z.GetCloseHour()) << endl;
    out << z.GetCloseHour() << endl;
    out << z.GetNumOfAnimals() << endl;
    //output the animals information.
    for(int i = 0; i < z.m_numOfAnimals; i++){
        if(typeid(*z.m_animals[i]) == typeid(Horse))
            z.OutHorse(out,dynamic_cast<Horse*>(z.m_animals[i]));
        if(typeid(*z.m_animals[i]) == typeid(GoldFish))
            z.OutGoldFish(out,dynamic_cast<GoldFish*>(z.m_animals[i]));
        if(typeid(*z.m_animals[i]) == typeid(Mermaid))
            z.OutMermaid(out,dynamic_cast<Mermaid*>(z.m_animals[i]));
        if(typeid(*z.m_animals[i]) == typeid(Flamingo))
            z.OutFlamingo(out,dynamic_cast<Flamingo*>(z.m_animals[i]));
    }
    return out;
} //output of Zoo

ifstream& operator>>( ifstream& ifs, Zoo& z ){
    z.Load(ifs);
    return ifs;
}//operator to read the zoo from a text file

void Zoo:: Save( ofstream& ofs ) const{
    ofs << *this;
}

void Zoo:: Load( ifstream& ifs ){
    char clean[5];
    int length;
    ifs >> length;
    this->m_name = new char[length + 1];
    ifs.getline(clean,1);
    ifs.getline(this->m_name,length + 1);
    ifs >> length;
    this->m_address = new char[length + 1];
    ifs.getline(clean,1);
    ifs.getline(this->m_address,length + 1);
    ifs >> this->m_ticketPrice;
    ifs >> length;
    this->m_openHours = new char[length + 1];
    ifs >> this->m_openHours;
    ifs >> length;
    this->m_closeHours = new char[length + 1];
    ifs >> this->m_closeHours;
    ifs >> this->m_numOfAnimals;
    this->m_animals = new Animal*[this->m_numOfAnimals];

    char kind[3];
    for(int i = 0; i < this->m_numOfAnimals; i++){
        ifs >> kind;
        if(strcmp(kind,"Ho") == 0){
            ifs >> length;
            char* color = new char[length + 1];
            int childs,preg,milk;
            float lifeTime;
            ifs >> color;
            ifs >> childs >> lifeTime >> preg >> milk >> length;
            char* type = new char[length + 1];
            ifs.getline(clean,1);
            ifs.getline(type,length + 1);
            Horse* newHorse = new Horse(color,childs,lifeTime,preg,milk,type);
            this->m_animals[i] = newHorse;
            continue;
        }
        if(strcmp(kind,"Go") == 0){
            ifs >> length;
            char* color = new char[length + 1];
            int childs,lifetime,preg,milk,fin,gills,avgW,avgL;
            ifs >> childs;
            ifs >> lifetime;
            ifs >> preg;
            ifs >> milk;
            ifs >> fin;
            ifs >> gills;
            ifs >> avgW;
            ifs >> avgL;
            GoldFish* newGold = new GoldFish(color,childs,lifetime,preg,milk,fin,gills,avgW,avgL);
            this->m_animals[i] = newGold;
            continue;
        }
        if(strcmp(kind,"Me") == 0){
            ifs >> length;
            char* color = new char[length + 1];
            int childs,preg,milk,fin,gills;
            float lifetime;
            ifs >> color;
            ifs >> childs;
            ifs >> lifetime;
            ifs >> preg >> milk >> fin >> gills;
            ifs >> length;
            char* firstName = new char[length +1];
            ifs >> firstName;
            ifs >> length;
            char* lastName = new char[length +1];
            ifs >> lastName;
            Mermaid* newMermaid = new Mermaid(color,childs,lifetime,preg,milk,fin,gills,firstName,lastName);
            this->m_animals[i] = newMermaid;
            continue;
        }
        if(strcmp(kind,"Fl") == 0){
            ifs >> length;
            char* color = new char[length + 1];
            ifs >> color;
            int childs,incubation, height;
            float lifetime;
            ifs >> childs;
            ifs >> lifetime;
            ifs >> incubation >> height;
            Flamingo* newFlamingo = new Flamingo(color,childs,lifetime,incubation,height);
            this->m_animals[i] = newFlamingo;
            continue;
        }
    }
}

void Zoo:: SaveBin( ofstream& ofs ) const{
    ofs.write((char*)this,sizeof(Zoo));
}