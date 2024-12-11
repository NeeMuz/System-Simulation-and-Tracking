using System;

public class Student
{
    public string Surname;
    public string Name;
    public string Middle_Name;
    public string Group;
    public int Age;
    public int[] Programming_Grades;
    public int[] Administration_Grades;
    public int[] Design_Grades;

    public Student(string surname, string name, string middle_Name, string group, int age)
    {
        Surname = surname;
        Name = name;
        Middle_Name = middle_Name;
        Group = group;
        Age = age;
        Programming_Grades = new int[0];
        Administration_Grades = new int[0];
        Design_Grades = new int[0];
    }

    public void AddGrade(string subject, int grade)
    {
        if (subject == "Programming")
        {
            Array.Resize(ref Programming_Grades, Programming_Grades.Length + 1);
            Programming_Grades[Programming_Grades.Length - 1] = grade;
        }
        else if (subject == "Administration")
        {
            Array.Resize(ref Administration_Grades, Administration_Grades.Length + 1);
            Administration_Grades[Administration_Grades.Length - 1] = grade;
        }
        else if (subject == "Design")
        {
            Array.Resize(ref Design_Grades, Design_Grades.Length + 1);
            Design_Grades[Design_Grades.Length - 1] = grade;
        }
    }

    public double GetAverageGrade(int[] grades)
    {
        double total = 0;
        for (int i = 0; i < grades.Length; i++)
        {
            total += grades[i];
        }
        return grades.Length > 0 ? total / grades.Length : 0;
    }

    public void PrintStudentInfo()
    {
        Console.WriteLine();

        Console.WriteLine("Full Name: " + Surname + " " + Name + " " + Middle_Name);

        Console.WriteLine();

        Console.WriteLine("Group: " + Group);

        Console.WriteLine();

        Console.WriteLine("Age: " + Age);

        Console.WriteLine();

        Console.WriteLine("Average Grade in Programming: " + GetAverageGrade(Programming_Grades));

        Console.WriteLine();

        Console.WriteLine("Average Grade in Administration: " + GetAverageGrade(Administration_Grades));

        Console.WriteLine();

        Console.WriteLine("Average Grade in Design: " + GetAverageGrade(Design_Grades));
    }
}

public class Program
{
    public static void Main()
    {
        Student student = new Student("Parker", "Johnson", "Williamson", "CS101", 22);

        student.AddGrade("Programming", 4);
        student.AddGrade("Programming", 5);
        student.AddGrade("Administration", 3);
        student.AddGrade("Design", 5);

        student.PrintStudentInfo();

        Console.WriteLine();
        Console.ReadKey();
    }
}
