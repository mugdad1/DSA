#include <iostream>
#include <string>
#include <stack>

struct Edit {
    enum Type { Insert, Delete };
    Type type;
    int pos;
    std::string text;
};

class TextEditor {
public:
    void insert(int pos, const std::string& text) {
        buffer.insert(pos, text);
        undoStack.push({Edit::Insert, pos, text});
        redoStack = std::stack<Edit>(); // Clear the redoStack
    }

    void erase(int pos, int length) {
        std::string removed = buffer.substr(pos, length);
        buffer.erase(pos, length);
        undoStack.push({Edit::Delete, pos, removed});
        redoStack = std::stack<Edit>(); // Clear the redoStack
    }

    void undo() {
        if (undoStack.empty()) return;
        Edit e = undoStack.top(); undoStack.pop();
        revert(e);
        redoStack.push(e);
    }

    void redo() {
        if (redoStack.empty()) return;
        Edit e = redoStack.top(); redoStack.pop();
        apply(e);
        undoStack.push(e);
    }

    const std::string& getText() const {
        return buffer;
    }

private:
    std::string buffer;
    std::stack<Edit> undoStack, redoStack;

    void apply(const Edit& e) {
        if (e.type == Edit::Insert) {
            buffer.insert(e.pos, e.text);
        } else {
            buffer.erase(e.pos, e.text.size());
        }
    }

    void revert(const Edit& e) {
        if (e.type == Edit::Insert) {
            buffer.erase(e.pos, e.text.size());
        } else {
            buffer.insert(e.pos, e.text);
        }
    }
};

int main() {
    TextEditor editor;
    editor.insert(0, "Hello");
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.insert(5, ", world");
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.undo();
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.redo();
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.erase(0, 5);
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.undo();
    std::cout << "Buffer: " << editor.getText() << std::endl;

    editor.redo();
    std::cout << "Buffer: " << editor.getText() << std::endl;

    return 0;
}