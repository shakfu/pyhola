#include <memory>

class Node;

typedef std::shared_ptr<Node> Node_SP;

class Node {
public:
    static Node_SP allocate(double w, double h);
    double get_width();
    void set_width(double w);

    double get_height();
    void set_height(double h);


protected:
    Node(double w, double h) : m_w(w), m_h(h) {}

private:
    double m_w = 100.0;
    double m_h = 60.0;
};

Node_SP Node::allocate(double w, double h) {
    return Node_SP(new Node(w, h));
}

double Node::get_width() {
    return m_w;
}

void Node::set_width(double w) {
    m_w = w;
}

double Node::get_height() {
    return m_h;
}

void Node::set_height(double h) {
    m_h = h;
}


// int main()
// {
//     Node_SP node = Node::allocate(10,5);

// }