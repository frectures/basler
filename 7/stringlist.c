#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stringlist
{
	char * * data;
	int capacity;
	int used;
};

enum { INITIAL_CAPACITY = 5 };

void stringlist__init(struct stringlist * self)
{
	self->data = malloc(INITIAL_CAPACITY * sizeof(char *));
	self->capacity = INITIAL_CAPACITY;
	self->used = 0;
}

void stringlist__done(struct stringlist * self)
{
	fprintf(stderr, "done not implemented yet :(\n");
	exit(1);
}

void stringlist__print(const struct stringlist * self)
{
	int i;
	printf("----- %d of %d entries used ---\n", self->used, self->capacity);
	for (i = 0; i < self->used; ++i)
	{
		puts(self->data[i]);
	}
}

int stringlist__capacity_is_exhausted(const struct stringlist * self)
{
	return self->used == self->capacity;
}

void stringlist__double_capacity(struct stringlist * self)
{
	fprintf(stderr, "double_capacity not implemented yet :(\n");
	exit(1);
}

void stringlist__add(struct stringlist * self, const char * s)
{
	if (stringlist__capacity_is_exhausted(self))
	{
		stringlist__double_capacity(self);
	}
	self->data[self->used] = malloc(strlen(s) + 1);
	strcpy(self->data[self->used], s);
	self->used++;
}

int main(void)
{
	struct stringlist words;
	stringlist__init(&words);

	stringlist__add(&words, "hello");
	stringlist__print(&words);

	stringlist__add(&words, "beautiful");
	stringlist__print(&words);

	stringlist__add(&words, "world");
	stringlist__print(&words);

	stringlist__done(&words);
	return 0;
}
