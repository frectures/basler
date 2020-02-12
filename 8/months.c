#include <assert.h>
#include <stdio.h>

const char * month_name_aac(int month_number)
{
	static const char names[12][4] = {
		"Jan", "Feb", "Mar", "Apr", "Mai", "Jun",
		"Jul", "Aug", "Sep", "Okt", "Nov", "Dez"
	};
	assert((month_number >= 1) && (month_number <= 12));
	return names[month_number - 1];
}

const char * month_name_apc(int month_number)
{
	static const char * names[12] = {
		"Jan", "Feb", "Mar", "Apr", "Mai", "Jun",
		"Jul", "Aug", "Sep", "Okt", "Nov", "Dez"
	};
	assert((month_number >= 1) && (month_number <= 12));
	return names[month_number - 1];
}

const char * month_name_ac(int month_number)
{
	static const char names[48] =
	"Jan\0Feb\0Mar\0Apr\0Mai\0Jun\0Jul\0Aug\0Sep\0Okt\0Nov\0Dez";
	assert((month_number >= 1) && (month_number <= 12));
	return &names[(month_number - 1) << 2];
}

const char * month_name_pc(int month_number)
{
	static const char * names =
	"Jan\0Feb\0Mar\0Apr\0Mai\0Jun\0Jul\0Aug\0Sep\0Okt\0Nov\0Dez";
	assert((month_number >= 1) && (month_number <= 12));
	return &names[(month_number - 1) << 2];
}

int main()
{
	int i;
	for (i = 1; i <= 12; ++i)
	{
		printf("%2i   %s   %s   %s   %s\n", i,
			month_name_aac(i), month_name_apc(i),
			month_name_ac(i), month_name_pc(i));
	}
	return 0;
}
