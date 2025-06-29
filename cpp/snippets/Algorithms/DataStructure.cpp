/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

namespace user
{
	class data
	{
	private:
		int x;
		static int assignment_count;
		static int n;
	public:
		friend ostream& operator<<(ostream &os, const data& a);
		friend istream& operator >> (istream &os, data& a);
		static void set_n(int n) {
			if (data::n == 0) data::n = n;
			else cout << "WRONG";
		}
		data& operator=(const data& a) {
			assignment_count++;
			if (assignment_count > 3 * data::n) {
				cout << "WRONG";
			}
			this->x = a.x;
			return *this;
		}

		bool operator<(const data& a) {
			return this->x < a.x;
		}
	};
};

int user::data::assignment_count = 0;
int user::data::n = 0;

ostream& user::operator<<(ostream &os, const data& a){
    return os << a.x;
}
istream& user::operator>>(istream &os, data& a){
    return os >> a.x;
}

//###INSERT CODE HERE -
void Swap(user::data &A, user::data &B)
{
	user::data temp = A;
	A = B;
	B = temp;
}

void select_sort(user::data* A, int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		if (min != i)
			Swap(A[min], A[i]);
	}
}

int datastructure_main(){
    int n;
    cin >> n;
    user::data::set_n(n);

    user::data *A = new user::data[n];
    for (int i = 0; i < n; i++){
        int x;
        cin >> A[i];
    }

    select_sort(A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
	return 0;
}
