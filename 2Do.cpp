#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Task{
public:
    std::string tag;
    std::string name;
    std::string color;
    int id;
    int number;
    int priority;

};
std::vector<Task> vec;
class editTaskOperator{
public:
    void editName(int id,std::string new_name){
        Task temp = vec[id];
        temp.name = new_name;
        vec[id]=temp;
    }
    void editTag(int id,std::string new_tag){
        Task temp = vec[id];
        temp.tag = new_tag;
        vec[id]=temp;
    }
    void editColor(int id,std::string new_color){
        Task temp = vec[id];
        temp.color = new_color;
        vec[id]=temp;
    }

};
class operations{
public:
    void createTask(int id, std::string name, std::string tag, std::string color){
        Task newTask;
        newTask.id = id;
        newTask.name = name;
        newTask.tag = tag;
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
    void editTask(int id){    //обращение к классу editTaskOperator и методам уже там
        std::cout<<"Выберите режим:"<<"\n"<<"1. Смена имени"<<"\n"<<"2. Смена цвета"<<"\n";
        int mode;
        std::cin>>mode;
        editTaskOperator editOperator;
        if(mode == 1){
            Task temp = vec[id];
            std::cout<<"Текущее имя: "<<temp.name<<"\n"<<"Введите новое имя: ";
            std::string newName;
            std::cin>>newName;
            editOperator.editName(id,newName);
        }
        if(mode == 2){
            Task temp = vec[id];
            std::cout<<"Текущий тег: "<<temp.name<<"\n"<<"Введите новый тег: ";
            std::string newName;
            std::cin>>newName;
            editOperator.editTag(id,newName);
        }
        
    }
    Task getTaskFromID(int id){
        Task tempTask = vec[id];//тут начинается нумерация с 0

    }
    std::vector<Task> getAllTasks(){
        std::vector<Task> tempVector;
        for(int id = 0; id<vec.size(); id++){
            Task temp=vec[id];
            tempVector.push_back(temp);

        }
        return tempVector;
    }
};
class sorter{
public:
    std::vector<Task> sortedOnlyTag(std::vector<Task> sourceVec,std::string sort_tag){
        std::vector<Task> sortedTasksVec;
        for (const auto& x : sourceVec) {
            if (x.tag == sort_tag) {
                sortedTasksVec.push_back(x);
            }
        }
        return sortedTasksVec;
    }
    std::vector<Task> sortedOnlyPriority(std::vector<Task> sourceVec,int priority_){
        std::vector<Task> sortedTasksVec;
        for (const auto& x : sourceVec) {
            if (x.priority == priority_) {
                sortedTasksVec.push_back(x);
            }
        }
        return sortedTasksVec;
    }
    std::vector<Task> sortedOnlyColor(std::vector<Task> sourceVec,std::string color_){
        std::vector<Task> sortedTasksVec;
        for (const auto& x : sourceVec) {
            if (x.color == color_) {
                sortedTasksVec.push_back(x);
            }
        }
        return sortedTasksVec;
    }
    

};
class consoleManager{
public:
    void start(){
        std::cout<<"----------------------"<<"\n";
        std::cout<<"Добро пожаловать в заметки!"<<"\n";
        std::cout<<"Выберите действие: \n 1.Новая заметка \n 2.Редактировать заметку \n 3.Вывод заметок \n";
        std::cout<<"----------------------"<<"\n";
        std::string mode;
        std::cin>>mode;
        int modeInt=0;
        try{
            modeInt = std::stoi(mode);
        }
        catch (...) {
            if(mode=="q"||mode=="quit"||mode=="exit"||mode=="e"){
                std::cout<<"\033[32mЗавершение работы\033[0m"<<'\n';
                std::abort();
            }
            else{
                std::cout<<"\033[31mНе распознанный ввод. Повторите попытку\033[0m\n";
            }
        }
        if(modeInt==1){

            operations oper;
            int id;std::string name;std::string tag;std::string color;
            std::cout<<"Введите имя: ";
            std::cin>>name;
            std::cout<<"Введите тег: ";
            std::cin>>tag;
            std::cout<<"Введите цвет: ";
            std::cin>>color;
            std::cout<<"\n";
            id = vec.size()+1;
            oper.createTask(id,name,tag,color);
            
        }
        if(modeInt==2){
            operations oper;
            int id;
            std::vector temp___vec = oper.getAllTasks();
            for(int i=0;i<temp___vec.size();i++){
                Task cur_task = temp___vec[i];
                std::cout<<i+1<<" "<<cur_task.name<<" "<<cur_task.tag<<"\n";
            }
            std::cout<<"Введите номер заметки для редактирования: ";
            std::cin>>id;
            try{
                if(vec.size()>=id){
                Task temp = vec[id-1];
                oper.editTask(id-1);
                }
                else{std::cout << "\033[31mЭлемент не найден\033[0m\n";}
            }
            catch(...){std::cout << "\033[31mЭлемент не найден\033[0m" << std::endl;}
            

        }
        if(modeInt==3){
            operations oper;
            // oper.printVectorSize();// заглушка
            std::vector<Task> returnVector = oper.getAllTasks();
            for(int id = 0;id<returnVector.size();id++){
                Task currentTask = returnVector[id];
                std::cout<<"Заметка "<<id+1<<". Имя: "<<currentTask.name<<" Тег: "<<currentTask.tag<<"\n";
            }
        }

    }
};



int main(){
    /* // ДЕБАГ
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
    new_vec = sort1.sortedOnlyTag(test_vec,"red");
    
    for(int i=0;i<new_vec.size();i++){
        Task temp_task = new_vec[i];
        std::cout<<"Task "<<i<<": "<<temp_task.name<<' '<<temp_task.tag<<"\n";
    }

    std::cout<<"\033[32mЗавершение работы\033[0m"<<'\n';
    */
    consoleManager mngr;
    while(1==1){
            mngr.start();

    

    }
    
    
    return 0;
}