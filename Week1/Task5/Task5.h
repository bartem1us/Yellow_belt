//
// Created by bartem1us on 27.03.2022.
//

#ifndef TEMPLATE_TASK5_H
#define TEMPLATE_TASK5_H
#include <map>
#include<string>
#include <tuple>
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
private:
    std::map<std::string ,TasksInfo> persons;
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const std::string& person) const;

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const std::string& person);


    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const std::string& person, int task_count);

};
#endif //TEMPLATE_TASK5_H
