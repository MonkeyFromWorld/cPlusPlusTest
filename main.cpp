
#include <vector>
#include <array>
#include "func.h" /* class Person */

#define TEST_OOP 1
#define TEST_VECTOR 0
#define TEST_ARRAY 0
/* ����ģ�壬template�������з��ͱ�̣�typename������ָ���� */
//�Զ������Ƶ����� add(a, b)
//����������ʾ���� add<int>(a, b)
//����ģ���ǲ�������ʽ����ת���ģ�����ʱ���ͱ����ϸ�ƥ��,static_cast<����>(a,b)
/*
- C++���������ȿ�����ͨ����
- �������ģ����Բ���һ�����õ�ƥ�䣬��ô��ѡ����ģ��
- Ҳ����ͨ����ģ��ʵ���б�<>�޶�������ֻƥ�亯��ģ��
 */
template <typename T1>
T1 add(T1 a, T1 b) {
    return a+b;
}

int main() {
#if TEST_OOP
    //ʹ��ʱ�������
    /*
    Person Li("Lao Li", 25),clone=Li;
    cout << Li.getName() << "," << Li.getAge() <<endl;
    cout << clone.getName() << "," << clone.getAge() <<endl;
    clone.setName("Nicholas C");
    clone.setAge(22);
    cout << "clone new: name: " << clone.getName() << ", age: " << clone.getAge() << endl;
    //ʹ��new�������
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

    Parent* test = new Child();//���������test��Ϊ���������Ĺ�������
    test->showName();//showNameָ�������
#endif
#if TEST_VECTOR
    vector<int> vi;//δ���峤��
    cout << vi.size() <<endl;//0

    //vector<int> a(10,1); //������10������Ԫ�ص�����,�Ҹ���ÿ��Ԫ�صĳ�ֵΪ1

    //���ȿ����Ǳ���
    //int count;
    //cin >> count;
    vector<float> vf(10);

    for(int i=0; i<vf.size(); i++) {
        vf[i] = i;
    }
    //���������ַ�ʽ
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
    cout << "assign+5��: ";
    for(int i : a) {
        cout << i <<", ";
    }
    a.assign(4,2);
    cout << "assign(4,2)��: ";
    for(int i : a) {
        cout << i <<", ";
    }
    cout << "\n";

    int b[7]={1,2,3,4,5,9,8};
    vector<int> c(b,b+7); //�������л�ó�ֵ
    for(int i : c) {
        cout << i <<", ";
    }
    cout << "\n";
    cout << c.front() <<", " << c.back() <<"\n";

    //������
    //for(vector<int>::iterator it=c.begin();it<c.end();it++) cout<<*it<<" ";;

    /*
     * ���⣬����������
    ��1��a.assign(b.begin(), b.begin()+3); //bΪ��������b��0~2��Ԫ�ع��ɵ���������a
    ��2��a.assign(4,2); //��aֻ��4��Ԫ�أ���ÿ��Ԫ��Ϊ2
    ��3��a.back(); //����a�����һ��Ԫ��
    ��4��a.front(); //����a�ĵ�һ��Ԫ��
    ��5��a[i]; //����a�ĵ�i��Ԫ�أ����ҽ���a[i]����2013-12-07
    ��6��a.clear(); //���a�е�Ԫ��
    ��7��a.empty(); //�ж�a�Ƿ�Ϊ�գ����򷵻�ture,�����򷵻�false
    ��8��a.pop_back(); //ɾ��a���������һ��Ԫ��
    ��9��a.erase(a.begin()+1,a.begin()+3); //ɾ��a�е�1�����ӵ�0�����𣩵���2��Ԫ�أ�Ҳ����˵ɾ����Ԫ�ش�a.begin()+1���𣨰�������һֱ��a.begin()+         3������������
    ��10��a.push_back(5); //��a�����һ�����������һ��Ԫ�أ���ֵΪ5
    ��11��a.insert(a.begin()+1,5); //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò�����ֵ5����aΪ1,2,3,4������Ԫ�غ�Ϊ1,5,2,3,4
    ��12��a.insert(a.begin()+1,3,5); //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���3��������ֵ��Ϊ5
    ��13��a.insert(a.begin()+1,b+3,b+6); //bΪ���飬��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���b�ĵ�3��Ԫ�ص���5��Ԫ�أ�������b+6������bΪ1,2,3,4,5,9,8         ������Ԫ�غ�Ϊ1,4,5,9,2,3,4,5,9,8
    ��14��a.size(); //����a��Ԫ�صĸ�����
    ��15��a.capacity(); //����a���ڴ����ܹ��������ɵ�Ԫ�ظ���
    ��16��a.resize(10); //��a������Ԫ�ظ�������10��������ɾ�����򲹣���ֵ���
    ��17��a.resize(10,2); //��a������Ԫ�ظ�������10��������ɾ�����򲹣���ֵΪ2
    ��18��a.reserve(100); //��a��������capacity��������100��Ҳ����˵���ڲ���a.capacity();��ʱ�򷵻�ֵ��100.���ֲ���ֻ������Ҫ��a��Ӵ������ݵ�ʱ���         �Ե������壬��Ϊ�⽫�����ڴ������������������a����������ʱ���Ի��Զ����ݣ���Ȼ���Ȼ�������ܣ�
    ��19��a.swap(b); //bΪ��������a�е�Ԫ�غ�b�е�Ԫ�ؽ��������Խ���
    ��20��a==b; //bΪ�����������ıȽϲ�������!=,>=,<=,>,<
     */
    /*
     * ������Ҫ���㷨��ʹ��ʱ��Ҫ����ͷ�ļ���
    #include<algorithm>
    ��1��sort(a.begin(),a.end()); //��a�еĴ�a.begin()������������a.end()��������������Ԫ�ؽ��д�С��������
    ��2��reverse(a.begin(),a.end()); //��a�еĴ�a.begin()������������a.end()��������������Ԫ�ص��ã��������У���a��Ԫ��Ϊ1,3,2,4,���ú�Ϊ4,2,3,1
    ��3��copy(a.begin(),a.end(),b.begin()+1); //��a�еĴ�a.begin()������������a.end()��������������Ԫ�ظ��Ƶ�b�У���b.begin()+1��λ�ã�����������        ʼ���ƣ����ǵ�ԭ��Ԫ��
    ��4��find(a.begin(),a.end(),10); //��a�еĴ�a.begin()������������a.end()��������������Ԫ���в���10�������ڷ������������е�λ��
     */
#endif
#if TEST_ARRAY
    array<int, 6> ai = {6,5,4,3,2,1};
    for(int i : ai)
        cout << i << ", ";
#endif
    return 0;
}