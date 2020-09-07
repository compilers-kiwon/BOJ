#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string patient,doctor;
	
	cin>>patient>>doctor;
	cout<<(doctor.length()>patient.length()?"no":"go")<<endl;
	
	return	0;
}
