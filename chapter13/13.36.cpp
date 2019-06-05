/*
 * Exercise 13.36: Design and implement the corresponding Folder class. That
 * class should hold a set that points to the Messages in that Folder.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <set>
#include <string>

class Folder;
class Message {
	friend class Folder;
	friend void swap(Message &, Message &);
	friend std::ostream& print(std::ostream &, const Message &);
	public:
		explicit Message(const std::string &str = "") : content(str) {}
		Message(const Message &m) : content(m.content), folders(m.folders)
	                                             { add_to_Folders(m); }
		Message& operator=(const Message &);
		~Message() { remove_from_Folders(); }
		void save(Folder &);
		void remove(Folder &);
	private:
		std::string content;
		std::set<Folder *> folders;
		void add_to_Folders(const Message &);
		void remove_from_Folders();
};

Message&
Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	content = rhs.content;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

class Folder {
	friend std::ostream& print(std::ostream &, const Folder &);
	public:
		explicit Folder(const std::string &str = ".") : name(str) {}
		Folder(const Folder &f) : name(f.name), messages(f.messages)
												{ add_to_Messages(f); }
		Folder& operator=(const Folder &);
		~Folder() { remove_from_Messages(); }
		void addMsg(Message *m) { messages.insert(m); }
		void remMsg(Message *m) { messages.erase(m); }
	private:
		std::string name;
		std::set<Message *> messages;
		void add_to_Messages(const Folder &);
		void remove_from_Messages();
};

// copy-control functions
Folder&
Folder::operator=(const Folder &rhs)
{
	remove_from_Messages();
	name = rhs.name;
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

// member functions
void
Folder::add_to_Messages(const Folder &f)
{
	for (auto m : f.messages)
		m->folders.insert(this);   // needs friend status
}

void
Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->folders.erase(this);    // needs friend status
}

void
Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void
Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void
Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void
Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;      // good practice
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.content, rhs.content);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

// non-member functions
std::ostream& print(std::ostream &os, const Message &m)
{
	os << "content: " << m.content << '\n';
	for (const auto f : m.folders)
		std::cout << f << ' ';
	return os;
}

std::ostream& print(std::ostream &os, const Folder &f)
{
	os << "name: " << f.name << '\n';
	for (const auto m : f.messages)
		std::cout << m << ' ';
	return os;
}
int main()
{
	Folder f("InBox");
	Folder k("New");
	Message a("Hello, there!");
	a.save(f);
	a.save(k);

	print(std::cout, a) << '\n';
	std::cout << "folder f: ";
	print(std::cout, f) << '\n';

	std::cout << "folder k: ";
	print(std::cout, k) << '\n';
	Folder x;
	x = k;
	std::cout << "folder x: ";
	print(std::cout, x) << '\n';
	print(std::cout, a) << '\n';
	return 0;
}
