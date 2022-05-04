#include "Task5.h"

void TeamTasks::AddNewTask(const std::string &person) {
    ++persons[person][TaskStatus::NEW];
}

const TasksInfo &TeamTasks::GetPersonTasksInfo(const std::string &person) const {
    return persons.find(person)->second;
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string &person, int task_count) {
    int a = persons[person][TaskStatus::NEW];
    int b = persons[person][TaskStatus::IN_PROGRESS];
    int c = persons[person][TaskStatus::TESTING];
    TasksInfo upgrade_tasks;
    TasksInfo untouched_tasks;

    if (task_count > a) {// task_count >NEW
        if (task_count  >= a + b) { //task_count >= NEW + IN_PROGRESS
            if (task_count >= c + a + b) {// new = 0 in_progress = 0
                persons[person][TaskStatus::NEW] = 0 ;
                persons[person][TaskStatus::IN_PROGRESS] = a ;
                persons[person][TaskStatus::TESTING]= b ;
                persons[person][TaskStatus::DONE] = c;
                upgrade_tasks[TaskStatus::IN_PROGRESS] = a;
                upgrade_tasks[TaskStatus::TESTING] = b ;
            }
        } else { // task_count < a + b  => task_count >a task_count < b
            persons[person][TaskStatus::NEW] = 0 ;
            persons[person][TaskStatus::IN_PROGRESS] += a ;
            upgrade_tasks[TaskStatus::IN_PROGRESS] = a;
            upgrade_tasks[TaskStatus::TESTING] = task_count - a;
            untouched_tasks[TaskStatus::TESTING] = c;
            untouched_tasks[TaskStatus::IN_PROGRESS] =  b - task_count +  a;
        }

    } else { // task_count < = a
        persons[person][TaskStatus::NEW] -= task_count;
        persons[person][TaskStatus::IN_PROGRESS]+= task_count;
        if (persons[person][TaskStatus::NEW] == task_count) {
            upgrade_tasks[TaskStatus::IN_PROGRESS] = task_count;
            untouched_tasks[TaskStatus::TESTING] = c;
            untouched_tasks[TaskStatus::IN_PROGRESS] = b;
        } else {
            upgrade_tasks[TaskStatus::IN_PROGRESS] = task_count;
            untouched_tasks[TaskStatus::NEW] = a - task_count;
            untouched_tasks[TaskStatus::TESTING] = c;
            untouched_tasks[TaskStatus::IN_PROGRESS] = b;
        }


    }
    return std::tie(upgrade_tasks,untouched_tasks);

}



