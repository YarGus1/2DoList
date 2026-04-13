#include <iostream>
#include <string>
#include <vector>


class Task{
public:
    std::string tag;
    std::string name;
    std::string color;
    int id;
    int number;

};

std::vector<Task> vec;
class editTaskOperator{
public:
    void editName(int id,std::string new_name){
        Task temp = vec[id];
        temp.name = new_name;
        vec[id]=temp;
    }
    void editTag(){

    }
    void editColor(){

    }

};
class operations{
public:
    void createTask(int id, std::string name, std::string tag, std::string color){
        Task newTask;
        newTask.id = id;
        newTask.name = name;
        vec.push_back(newTask);
    }
    void deleteTask(int id){
        vec.erase(vec.begin() + id);
    }
    void printVectorSize(){
        std::cout<<vec.size()<<'\n';
    }
    void inputTask(){
        std::string name;
        std::cout<<"Ввод задачи"<<'\n';
        std::cin>>name;
        int len = vec.size();
        createTask(len,name,"new","red");
    }
    void editTask(){    //обращение к классу editTaskOperator и методам уже там
        int id;
        std::cout<<"    Режим редактирования:"<<"\n"<<"Введите номер заметки:"<<"\n";
        std::cin>>id;
        std::cout<<"Выберите режим:"<<"\n"<<"1. Смена имени"<<"\n"<<"2. Смена цвета"<<"\n";
        int mode;
        std::cin>>mode;
        editTaskOperator editOperator;
        if(mode == 1){
            std::cout<<"Текущее имя: "<<"\n"<<"Введите новое имя";
            std::string newName;
            std::cin>>newName;
            editOperator.editName(id,newName);
        }
        
    }
    // Task getTask(){

    // }
};





int main(){
    operations operat;
    operat.inputTask();
    std::cout<<vec[0].name<<std::endl;
    operat.editTask();

    
    return 0;
}