#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct heap
{
	int * data;
	int capacity;
	int used;
	// Die Zellen von 1 bis used INKLUSIVE beinhalten die eigentliche Daten, Zelle 0 wird ignoriert.
};

void heap__init(struct heap * self, int capacity)
{
	self->data = malloc((capacity + 1) * sizeof(int));
	self->capacity = capacity;
	self->used = 0;
	// TODO sinnvollen Wert an Stelle 0 ablegen

}

void heap__done(struct heap * self)
{
	assert(self->data);
	free(self->data);
	self->data = NULL;
}

void print_spaces(int n)
{
	while (n--)
	{
		putchar(' ');
	}
}

int is_last_on_line(int i)
{
	return (i & (i + 1)) == 0;
}

void heap__print_2d(const struct heap * self, int n)
{
	static const int space_table[32] = {
		0,
		0,
		3, 3,
		7, 7, 7, 7,
		15, 15, 15, 15, 15, 15, 15, 15,
		31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31
	};

	const char * potential_newline = "";
	int spaces = space_table[n];

	int i;
	for (i = 1; i <= n; ++i)
	{
		printf(potential_newline);
		potential_newline = "";

		print_spaces(spaces);
		printf("%2d", self->data[i]);
		print_spaces(spaces);

		if (is_last_on_line(i))
		{
			potential_newline = "\n";
			spaces /= 2;
		}
	}
}

void heap__print(const struct heap * self)
{
	if (self->used <= 31)
	{
		heap__print_2d(self, self->used);
	}
	else
	{
		heap__print_2d(self, 31);
		printf("...");
	}
	puts("\n---------------------------------------------------------------");
}

int heap__valid_index(const struct heap * self, int index)
{
	return (index >= 0) && (index <= self->used);
}

int heap__at(const struct heap * self, int index)
{
	if (!heap__valid_index(self, index))
	{
		printf("Ungültiger Index bei Zugriff auf Heap: %d > %d\n\n", index, self->used);
		heap__print(self);
		exit(1);
	}
	return self->data[index];
}

void heap__assert(const struct heap * self)
{
	// TODO

}

void heap__insert(struct heap * self, int element)
{
	assert(self->used < self->capacity);
	// TODO

	heap__assert(self);
}

int heap__remove_minimum(struct heap * self)
{
	assert(self->used > 0);
	// TODO

	heap__assert(self);
	// TODO
	return -1;
}

int main()
{
	struct heap test;
	heap__init(&test, 31);

	heap__insert(&test, 13);
	heap__print(&test);
	heap__insert(&test, 19);
	heap__print(&test);
	heap__insert(&test, 37);
	heap__print(&test);
	heap__insert(&test, 29);
	heap__print(&test);
	heap__insert(&test, 17);
	heap__print(&test);
	heap__insert(&test, 11);
	heap__print(&test);
	heap__insert(&test, 23);
	heap__print(&test);

	while (test.used > 0)
	{
		heap__remove_minimum(&test);
		heap__print(&test);
	}

	heap__done(&test);
	return 0;
}
