#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*  MAP Demo*/


int SampleMapDemo()
{
    std::map <string,string> m_dist;
    m_dist["Ram"] = "Test1";
    m_dist.insert({"Shyam","Test2"});// C++11 initializer list style
    m_dist.insert({"Madhu","Test3"});// C++11 initializer list style

    auto it_1 = m_dist.emplace_hint(m_dist.begin(),"Jadhu","Test5");
    m_dist.emplace_hint(it_1, "Radhu", "Test6");

    for (const auto& entry : m_dist) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
    std::string key="Madhu";
    auto it = m_dist.find(key);
    if(it != m_dist.end())
      m_dist.erase(it);

    // After Erasing
    std::cout << "After Erasing" << std::endl;
    for (const auto& entry : m_dist) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
    return 0;
}

int stdudentInfoMapDemo()
{

    class Student
    {
    public:
        int roll_nbr;
        std::string name;

        bool operator<(const Student &ob) const
        {
            return roll_nbr < ob.roll_nbr;
        }
    };
    std::map<Student, int> m_studentInfo;
    // Create Student objects
    Student s1{101, "Alice"};
    Student s2{102, "Bob"};
    Student s3{100, "Charlie"};
    // Insert students and their marks into the map
    m_studentInfo.insert({s1, 85});
    m_studentInfo.insert({s2, 90});
    m_studentInfo.insert({s3, 78});

    for (auto &studentInfo : m_studentInfo)
    {
        std::cout << "Roll_nbr = " << studentInfo.first.roll_nbr << "\n"
                  << "Name = " << studentInfo.first.name << "\n"
                  << "Grade = " << studentInfo.second << std::endl;
    }
    return 0;
}

/* Vector*/

void VectorDemo()
{
    std::vector<int> m_vec;

    for(int i =0;i< 10;i++)
      m_vec.push_back(i);

     
    std::vector<int>::iterator it;
    for(it= m_vec.begin();it != m_vec.end();++it)
       std::cout<<*it << " ";
    std::cout << std::endl;
    std::cout << "Delete 2nd element" << "\n";
    int key = 2;

     auto it_2 =std::find(m_vec.begin(),m_vec.end(),key);
     
    if (it_2 != m_vec.end())
    {
        m_vec.erase(it);
    }

}
int main()
{
   // SampleMapDemo();
   // stdudentInfoMapDemo();
     VectorDemo();
    return 0;
}
