
// Main topics: Memory allocation, pointers to members, references, switch statement

## Memory Allocation:
- In C: heap allocation = malloc + free:
- In C++: heap allocation = new + delete

	int main(void)
	{
	    int *ptr; // declare the pointer
	    
	    ptr = new int; // allocate memory
	    *ptr = 45 // assign a value
	    std::cout << "ptr value: " << *ptr << std::endl; // print the value
	    delete ptr; // deallocate memory
	    return (0);
	}

add declaration of arrays of objects like ex01:
Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

## Pointers to members
this is a hidden pointer inside every non-static member function. It points to the current object that called the function. So inside Zombie::announce(), this->name means “the name of this zombie object.”

You could also write just name inside the member function, but this->name makes it very clear that you are using the member variable.

## References
- A reference is somehow like a dereferenced pointer

Once it's defined it will always be referencing the same value

You cannot declare a reference without assigning it a value directly

References are constant, you can't change what it references after the declaration

A reference cannot be void, unlike a pointer that can be void

## Using pointers and references
	std::string	brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

## Explained ex03
	Why this happens
	The choice comes from the behavior the exercise wants.
	A reference must be initialized immediately and cannot be null.
	A pointer can start empty and be assigned later.

	So:
	HumanA needs a reference because it is always armed.
	HumanB needs a pointer because it may start unarmed.

	Future rule
	When a class must always have an object, use a reference.
	When a class may have none at first, use a pointer.

## Switch statement

- Better than many ifs

	swtich (av[2][0])
	{
    case '+':
        printf("%d", atoi(av[1]) + atoi(av[3]));
        break;
    case '-':
        printf("%d", atoi(av[1]) - atoi(av[3]));
        break;
    case '*':
        printf("%d", atoi(av[1]) * atoi(av[3]));
        break;
    case '/':
        printf("%d", atoi(av[1]) / atoi(av[3]));
        break;
    case '%':
        printf("%d", atoi(av[1]) % atoi(av[3]));
        break;
	}