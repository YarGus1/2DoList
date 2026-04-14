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
class sorter{
public:
    std::vector<Task> sortedByTag(std::vector<Task> sourceVec,std::string sort_tag){
        std::vector<Task> sortedTasksVec;
        for (const auto& x : sourceVec) {
            if (x.tag == sort_tag) {
                sortedTasksVec.push_back(x);
            }
        }
        return sortedTasksVec;
    }
};




int main(){
    operations operat;
    //объявление тестовых тасков для дебага сортировки
    std::vector<Task> test_vec;
    std::vector<Task>  new_vec;

    Task firstTask;
    firstTask.tag="blue";
    firstTask.name = "HelloTask";
    test_vec.push_back(firstTask);
    Task secondTask;
    secondTask.tag="blue";
    secondTask.name = "HelloTask2";
    test_vec.push_back(secondTask);
    Task thirdTask;
    thirdTask.tag="red";
    thirdTask.name = "HelloTask3";
    test_vec.push_back(thirdTask);

    sorter sort1;
    new_vec = sort1.sortedByTag(test_vec,"red");

    for(int i=0;i<new_vec.size();i++){
        Task temp_task = new_vec[i];
        std::cout<<"Task "<<i<<": "<<temp_task.name<<' '<<temp_task.tag<<"\n";
    }

    
    
    return 0;
}