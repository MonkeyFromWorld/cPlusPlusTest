
#include <vector>
#include <array>
#include "func.h" /* class Person */

#define TEST_OOP 1
#define TEST_VECTOR 0
#define TEST_ARRAY 0
/* 函数模板，template声明进行泛型编程，typename声明泛指类型 */
//自动类型推到调用 add(a, b)
//具体类型显示调用 add<int>(a, b)
//函数模板是不允许隐式类型转换的，调用时类型必须严格匹配,static_cast<类型>(a,b)
/*
- C++编译器优先考虑普通函数
- 如果函数模板可以产生一个更好的匹配，那么就选择函数模板
- 也可以通过空模板实参列表<>限定编译器只匹配函数模板
 */
template <typename T1>
T1 add(T1 a, T1 b) {
    return a+b;
}

int main() {
#if TEST_OOP
    //使用时定义对象
    /*
    Person Li("Lao Li", 25),clone=Li;
    cout << Li.getName() << "," << Li.getAge() <<endl;
    cout << clone.getName() << "," << clone.getAge() <<endl;
    clone.setName("Nicholas C");
    clone.setAge(22);
    cout << "clone new: name: " << clone.getName() << ", age: " << clone.getAge() << endl;
    //使用new定义对象
    auto* Lo = new Person("Lao Lo", 30);
    cout << Lo->getAge() <<endl;

    float addRes = add(2.2,5.0);
    cout << addRes <<endl;
     */
    auto* father = new Parent("xx", 18, 1);
    father->showName();

    auto* child = new Child("cc", 16, 2);
    child->showNameAgain();
    child->showName();

    Parent* test = new Child();//这种情况下test是为子类与夫类的公共部分
    test->showName();//showName指向子类的
#endif
#if TEST_VECTOR
    vector<int> vi;//未定义长度
    cout << vi.size() <<endl;//0

    //vector<int> a(10,1); //定义了10个整型元素的向量,且给出每个元素的初值为1

    //长度可以是变量
    //int count;
    //cin >> count;
    vector<float> vf(10);

    for(int i=0; i<vf.size(); i++) {
        vf[i] = i;
    }
    //遍历的俩种方式
    /*
    for(int i=0; i<vf.size(); i++) {
        cout << vf[i] <<", ";
    }
     */
    cout << "\n";
    for(float i : vf) {
        cout << i <<", ";
    }
    cout << "\n";

    vector<int> a(vf.begin(),vf.begin()+3);
    for(int i : a) {
        cout << i <<", ";
    }
    a.assign(vf.begin(), vf.begin()+5);
    cout << "assign+5后: ";
    for(int i : a) {
        cout << i <<", ";
    }
    a.assign(4,2);
    cout << "assign(4,2)后: ";
    for(int i : a) {
        cout << i <<", ";
    }
    cout << "\n";

    int b[7]={1,2,3,4,5,9,8};
    vector<int> c(b,b+7); //从数组中获得初值
    for(int i : c) {
        cout << i <<", ";
    }
    cout << "\n";
    cout << c.front() <<", " << c.back() <<"\n";

    //迭代器
    //for(vector<int>::iterator it=c.begin();it<c.end();it++) cout<<*it<<" ";;

    /*
     * 此外，还有许多操作
    （1）a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
    （2）a.assign(4,2); //是a只含4个元素，且每个元素为2
    （3）a.back(); //返回a的最后一个元素
    （4）a.front(); //返回a的第一个元素
    （5）a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07
    （6）a.clear(); //清空a中的元素
    （7）a.empty(); //判断a是否为空，空则返回ture,不空则返回false
    （8）a.pop_back(); //删除a向量的最后一个元素
    （9）a.erase(a.begin()+1,a.begin()+3); //删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）
    （10）a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5
    （11）a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
    （12）a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
    （13）a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
    （14）a.size(); //返回a中元素的个数；
    （15）a.capacity(); //返回a在内存中总共可以容纳的元素个数
    （16）a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
    （17）a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
    （18）a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能）
    （19）a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
    （20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
     */
    /*
     * 几种重要的算法，使用时需要包含头文件：
    #include<algorithm>
    （1）sort(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
    （2）reverse(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
    （3）copy(a.begin(),a.end(),b.begin()+1); //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开        始复制，覆盖掉原有元素
    （4）find(a.begin(),a.end(),10); //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
     */
#endif
#if TEST_ARRAY
    array<int, 6> ai = {6,5,4,3,2,1};
    for(int i : ai)
        cout << i << ", ";
#endif
    return 0;
}