#include<iostream>
#include<fstream>
#include<vector>
#include<string>
 using namespace std;


 struct Task{
    string description;
    bool completed;
};

vector<Task>tasks;
const string filename="tasks.txt";

void loadTasks(){
    tasks.clear();

    ifstream file(filename);

    if (!file.is_open()) return;

    string line;

    while (getline(file, line)){
        Task task;

        if (line.substr(0, 1)=="[X]"){
            task.completed=true;
            task.description=line.substr(4);
        }else{
            task.completed = false;
            task.description = line.substr(4);
        }
        tasks.push_back(task);
    }

    file.close();
}

void saveTasks(){
    ofstream file(filename);
    for (const auto& task:tasks){
        file<<(task.completed? "[X]":"[ ]")<<task.description<<endl;
    }
    file.close();
}

void addTask(){
    cin.ignore();
    Task newTask;
    cout<<"Enter task description: ";
    getline(cin,newTask.description);
    newTask.completed=false;
    tasks.push_back(newTask);
    saveTasks();
    cout <<"Task added successfully!\n";
}

void viewTasks(){
    if (tasks.empty()){
        cout <<"No tasks found.\n";
        return;
    }
    cout<<"\nTo-Do List\n";
    for (size_t i = 0;i< tasks.size();++i) {
        cout<<i+1<<". "<<(tasks[i].completed ?"[X]":"[ ]")<<tasks[i].description<< endl;
    }
}

void deleteTask(){
    viewTasks();
    if(tasks.empty())return;

    int index;
    cout <<"Enter task number to delete:  ";
    cin >> index;

    if (index< 1||index>tasks.size()) {
        cout <<"Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin()+index-1);
    saveTasks();
    cout<<"Task deleted successfully!\n";
}

void markCompleted() {
    viewTasks();
    if(tasks.empty())return;

    int index;
    cout<<"Enter task number to mark as completed: ";
    cin >> index;

    if (index<1 || index>tasks.size()){
        cout<<"Invalid task number.\n";
        return;
    }

    tasks[index - 1].completed = true;
    saveTasks();
    cout<<"Task marked as completed!\n";
}

void showMenu() {
    cout<<"\ To-Do List App\n";
    cout<<"(1). View Tasks\n";
    cout<<"(2). Add Task\n";
    cout<<"(3). Delete Task\n";
    cout<<"(4). Mark Task as Completed\n";
    cout<<"(5). Exit\n";
    cout<<"Choose an option:  ";
}



  int main(){

   loadTasks();

   int choice;
     showMenu();

      cin>>choice;
       if(choice==1){
        viewTasks();
       }else if(choice==2){
       addTask();
       }else if(choice==3){
       deleteTask();
       }else if(choice==4){
        markCompleted();
       }else if(choice==5){
       cout<<"exiting....\n";

       }else{

       cout<<"invalid option. try again.\n";
       }



   return 0;






  }
