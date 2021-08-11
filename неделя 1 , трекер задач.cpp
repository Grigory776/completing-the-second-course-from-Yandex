// неделя 1 , трекер задач.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include<iostream>
#include<string>
#include<map>
#include<tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

TasksInfo operator-(TasksInfo lhs,TasksInfo rhs) {
    TasksInfo res;
    auto tmp = tie(lhs[TaskStatus::NEW], lhs[TaskStatus::IN_PROGRESS], lhs[TaskStatus::TESTING], lhs[TaskStatus::DONE]);
    if (abs(lhs[TaskStatus::NEW] - rhs[TaskStatus::NEW]) != 0)
        res[TaskStatus::NEW] = abs(lhs[TaskStatus::NEW] - rhs[TaskStatus::NEW]);

    if (abs(lhs[TaskStatus::IN_PROGRESS] - rhs[TaskStatus::IN_PROGRESS]) != 0)
        res[TaskStatus::IN_PROGRESS] = abs(lhs[TaskStatus::IN_PROGRESS] - rhs[TaskStatus::IN_PROGRESS]);

    if (abs(lhs[TaskStatus::TESTING] - rhs[TaskStatus::TESTING]) != 0)
        res[TaskStatus::TESTING] = abs(lhs[TaskStatus::TESTING] - rhs[TaskStatus::TESTING]);

   

    return res;
}


class TeamTasks {
public:

    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return Sotr.at(person);
    }
    void AddNewTask(const string& person) {// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
        Sotr[person][TaskStatus::NEW] += 1;
    }
    // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
        TasksInfo t, t1;
        if (Sotr.at(person).size() == 0) return tie(t, t1);

        size_t a = Sotr[person][TaskStatus::NEW];
        size_t b = Sotr[person][TaskStatus::IN_PROGRESS];
        size_t c = Sotr[person][TaskStatus::TESTING];

        size_t KolZad = a + b + c;

        TasksInfo result1;
        TasksInfo result2;

        if (task_count > KolZad) task_count = KolZad;
        while (task_count != 0) {
            if (a != 0) {
                result1[TaskStatus::IN_PROGRESS] += 1;
                Sotr.at(person)[TaskStatus::IN_PROGRESS] += 1;
                Sotr.at(person)[TaskStatus::NEW] -= 1;
                a--;
                task_count--;
            }
            else if (b != 0) {
                result1[TaskStatus::TESTING] += 1;
                Sotr.at(person)[TaskStatus::TESTING] += 1;
                Sotr.at(person)[TaskStatus::IN_PROGRESS] -= 1;
                b--;
                task_count--;
            }
            else if (c != 0) {
                result1[TaskStatus::DONE] += 1;
                Sotr.at(person)[TaskStatus::DONE] += 1;
                Sotr.at(person)[TaskStatus::TESTING] -= 1;
                c--;
                task_count--;
            }

        }
        result2 = Sotr.at(person) - result1;

        return tie(result1, result2);
    }

   
    
private:
    map<string, TasksInfo> Sotr;
};

void PrintTasksInfo(const TasksInfo& tasks_info) {
    if (tasks_info.count(TaskStatus::NEW)) {
        std::cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        std::cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        std::cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        std::cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
    }
}

void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}

int main()
{
    TeamTasks tasks;
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;

    /* TEST 1 */
    std::cout << "Alice" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice",
        2);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
    PrintTasksInfo(updated_tasks, untouched_tasks);

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;



    return 0;
}

