#include <iostream>
#include <sqlite3.h>
#include <string>

class Database
{
public:
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("timetables.db", &DB);
    
    Database(){}
    ~Database()
    {
      sqlite3_close(DB);
    }
    static int callback(void* data, int argc, char** argv, char** azColName)//Function from https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
    {
      int i;
      fprintf(stderr, "%s: ", (const char*)data);
  
      for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      }
  
      printf("\n");
      return 0;
     }
    void database_innit()
    {
      //Create the database and enter initial data, has already been run, delete .db file to re-run

      std::string sql = "CREATE TABLE STUDENT("
      "student_id TEXT PRIMARY KEY NOT NULL,"
      "name TEXT NOT NULL,"
      "course_id TEXT NOT NULL,"
      "email TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO STUDENT VALUES ('10','Benjamin','1','benjamin@uni.com')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO STUDENT VALUES ('12','Bob','1','bob@uni.com')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO STUDENT VALUES ('13','John','1','john@uni.com')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO STUDENT VALUES ('14','Anna','2','anna@uni.com')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO STUDENT VALUES ('15','Julie','2','julie@uni.com')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "SELECT * FROM STUDENT";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);


      sql = "CREATE TABLE GROUPSTUDENT("
      "group_id TEXT PRIMARY KEY NOT NULL,"
      "student_id TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO GROUPSTUDENT VALUES ('1','10')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO GROUPSTUDENT VALUES ('1','12')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO GROUPSTUDENT VALUES ('1','13')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO GROUPSTUDENT VALUES ('2','14')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO GROUPSTUDENT VALUES ('2','15')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "SELECT * FROM GROUPSTUDENT";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);


       sql = "CREATE TABLE COURSE("
      "course_id TEXT PRIMARY KEY NOT NULL,"
      "name TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO COURSE VALUES ('1','Computer science')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO COURSE VALUES ('2','Philosophy')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "SELECT * FROM COURSE";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);



       sql = "CREATE TABLE MODULE("
      "module_id TEXT PRIMARY KEY NOT NULL,"
      "name TEXT NOT NULL,"
      "course_id TEXT NOT NULL,"
      "teacher TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO MODULE VALUES ('40005CEM','Computer science 40005','1','Smith')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO MODULE VALUES ('40010CEM','Computer science 40010','1','Stone')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

      sql = "INSERT INTO MODULE VALUES ('60005PHI','Philosophy 60005','2','LiPin')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO MODULE VALUES ('60010PHI','Philosophy 60010','2','Frank')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "SELECT * FROM MODULE";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);


       sql = "CREATE TABLE ROOM("
      "room_id TEXT PRIMARY KEY NOT NULL,"
      "building TEXT NOT NULL,"
      "floor TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO ROOM VALUES ('56','Building 1','1')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO ROOM VALUES ('58','Building 1','2')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO ROOM VALUES ('16','Building 2','1')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "SELECT * FROM ROOM";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);



       sql = "CREATE TABLE SCHEDULE("
      "class_id TEXT PRIMARY KEY NOT NULL,"
      "module_id TEXT NOT NULL,"
      "room_id TEXT NOT NULL,"
      "group_id TEXT NOT NULL,"
      "date TEXT NOT NULL," 
      "time TEXT NOT NULL)";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('1','40005CEM','56','3','2021-05-21','13:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('2','40010CEM','56','3','2021-05-21','14:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('3','40005CEM','56','3','2021-05-23','13:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('4','40010CEM','56','3','2021-05-23','15:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('5','60005PHI','58','2','2021-05-22','15:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "INSERT INTO SCHEDULE VALUES ('6','60010PHI','58','2','2021-05-23','15:00')";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

       sql = "SELECT * FROM SCHEDULE";
      sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    }
};

class Schedule: public Database
{
public:
    Schedule(){}
    
    void create_schedule_table()
    {
        std::string sql = "CREATE TABLE SCHEDULE("
                          "schedule_id TEXT PRIMARY KEY NOT NULL,"
                          "module_id TEXT NOT NULL,"
                          "room_id TEXT NOT NULL,"
                          "group_id TEXT NOT NULL,"
                          "date TEXT NOT NULL,"
                          "time TEXT NOT NULL);";
        
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK)
        {
            std::cout << "Error/Table already exists";
        }
        else{
            std::cout << "Schedule Table Created";
        }
    }
    
    void display_schedule_table(std::string value)
    {
        std::cout << "group select";
        std::cout << value;
        std::string space = "'";
        std::string query = "SELECT * FROM SCHEDULE WHERE group_id ="+space+value+space+" ;";
        std::cout << std::endl;
        
        /*if (value!="2" | value!="3")
        {
            std::cout << "student select";
            query = "SELECT * FROM SCHEDULE WHERE group_id = (SELECT group_id FROM GROUPSTUDENT WHERE student_id ="+space+value+space+");";
            std::cout << std::endl << query << std::endl;
        }*/
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    }
    
    void insert_into_schedule_table()
    {
        std::string class_id, module_id, room_id, group_id, date, time;
        std::cout << "Enter class_id";
        std::cin >> class_id;
        std::cout << "Enter module_id";
        std::cin >> module_id;
        std::cout << "Enter room_id";
        std::cin >> room_id;
        std::cout << "Enter group_id";
        std::cin >> group_id;
        std::cout << "Enter date";
        std::cin >> date;
        std::cout << "Enter time";
        std::cin >> time;
        std::cout << std::endl;
        std::string space = "'";
        std::string sql = "";
        
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) {
            std::cout << std::endl << "Error Insert/Records already exist" << std::endl;
        }
        else
            std::cout << "Records created Successfully!" << std::endl;
        
    }
    
};

class Group: public Schedule
{
public:
    Group(){}
    ~Group(){}
    
    void create_group_table()
    {
        std::string sql = "CREATE TABLE GROUPSTUDENT("
                          "group_id TEXT PRIMARY KEY NOT NULL,"
                          "student_id TEXT NOT NULL);";
                          
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK)
        {
            std::cout << "Error/Table already exists";
        }
        else{
            std::cout << "Group Table Created";
        }
    }
    void display_group_table()
    {
        std::string space = "'";
        std::string query = "SELECT * FROM GROUP";
        std::cout << std::endl;
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    }
    
    void insert_into_group_table()
    {
        std::string group_id, s_id;
        std::cout << "Enter students group ID";
        std::cin >> group_id;
        std::cout << "Enter students ID";
        std::cin >> s_id;
        std::string space = "'";
        std::string sql = "INSERT INTO GROUP VALUES("+space+group_id+space+","+space+s_id+space+");";
        std::cout << sql;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) {
            std::cout << std::endl << "Error Insert/Records already exist" << std::endl;
        }
        else
            std::cout << "Records created Successfully!" << std::endl;
        
    }
};

class Student: public Group
{
public:
    /*sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("timetables.db", &DB);*/
    Student()
    {
      
    }
    
    ~Student()
    {
        sqlite3_close(DB);
    }
    
    void create_student_table()
    {
        std::string sql = "CREATE TABLE STUDENT("
          "student_id TEXT PRIMARY KEY NOT NULL,"
          "name TEXT NOT NULL,"
          "course TEXT NOT NULL,"
          "email TEXT NOT NULL);";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK)
        {
            std::cout << "Error/Table already exists";
        }
        else{
            std::cout << "Student Table Created";
        }
        //sqlite3_close(DB);
    }
    
    void display_student_table()
    {
        std::string query = "SELECT * FROM STUDENT;";
        //std::cout << query << std::endl;
        std::cout << std::endl;
        sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
        //sqlite3_close(DB);
    }
    
    void query()
    {
        //string query = "SELCT * FROM students;";
        std::string query_data;
        std::cout << "Enter query data" << std::endl;
        std::getline(std::cin, query_data);
        //std::cin >> query_data;
        //std::cout << query_data << std::endl;
        sqlite3_exec(DB, query_data.c_str(), callback, NULL, NULL);
        //sqlite3_close(DB);
    }
  
    void insert_into_student_table()
    {
        
        std::string s_id, s_name, s_course, s_email;
        std::cout << "Enter students ID:"; //****Coming Soon when working ******
        std::cin >> s_id;
        std::cout << "Enter students name:";
        std::cin >> s_name;
        std::cout << "Enter students course:";
        std::cin >> s_course;
        std::cout << "Enter students email:";
        std::cin >> s_email;
        std::string space = "'";
        std::string sql = "INSERT INTO STUDENT VALUES("+space+s_id+space+","+space+s_name+space+","+space+s_course+space+","+space+s_email+space+");";
        //sql = std::format("INSERT INTO STUDENT VALUES({},'{}','{}','{}')", s_id, s_name, s_course, s_email);
        std::cout << std::endl << sql << std::endl;
         
        //std::string sql = "INSERT INTO STUDENT VALUES(1234, 'Benjamin', 'CompSci', 'benjamin@uni.com')";//for now is premade query
        //std::cout << sql;

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) {
            std::cout << std::endl << "Error Insert/Records already exist" << std::endl;
        }
        else
            std::cout << "Records created Successfully!" << std::endl;
        //sqlite3_close(DB);
    }
    
};



int main(int argc, char** argv)
{
    Student s1;//Initialise object from everything will run through
    //s1.database_innit();Preload database with some data
    //s1.query();
    //s1.create_student_table();
    //s1.create_group_table();
    //s1.create_schedule_table();
    //s1.insert_into_group_table();
    //s1.display_group_table();
    //s1.display_schedule_table();
    
    int choice;//****MENUUUUUUUUUUUUUUUUUUUUU******BELOWWW
    bool x = true;
    while (x)
    {
      std::cout << std::endl << "*****MENU*****" << std::endl;
      std::cout << "1.Manage Data\n2.Manage Timetable\n3.Display Timetable\n\n";
      std::cin >> choice;
      switch (choice) 
      {
        case 1:
          std::cout << "1.Student(s)\n2.Course(s)\n3.Module(s)4.Room(s)\n\n";
          std::cin >> choice;
          switch (choice)
          {
            case 1:
              std::cout << "1.Create\n2.Delete\n\n";
              break;
            case 2:
              std::cout << "1.Create\n2.Delete\n\n";
              break;
            case 3:
              std::cout << "1.Create\n2.Delete\n\n";
              break;
            case 4:
              std::cout << "1.Create\n2.Delete\n\n";
              break;
          }
          break;
        case 2:
          std::cout << "1.Create Class\n2.Delete Class\n\n";
          std::cin >> choice;
          switch (choice)
          {
            case 1:
              std::cout << "Class Creation HERE\n\n";
              break;
            case 2:
              std::cout << "Class Deletion HERE\n\n";
          }
          break;
        case 3:
          std::cout << "1.By Student ID\n2.By Group ID\n\n";
          std::cin >> choice;
          switch (choice)
          {
            case 1:
              std::cout << "Displaying by Student ID...\n\n";
              s1.display_schedule_table("13");
              break;
            case 2:
              std::cout << "Displaying by Group ID...\n\n";
              s1.display_schedule_table("2");
              break;
          }
          break;
      }
  }
    return (0);
}