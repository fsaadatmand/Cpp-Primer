/*
 * Exercise 13.34: Write the Message class as described in this section.
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
	public:
		void addMsg(Message *);
		void remMsg(Message *);
};

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

int main()
{
	return 0;
}
