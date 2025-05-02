#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct Edit {
    enum Type { Insert, Delete };
    Type type;
    int pos;
    string text;
};

class TextEditor {
public:
    void insert(int pos, const string& text) {
        if (pos > buffer.size()) return; // Check for valid position
        buffer.insert(pos, text);
        undoStack.push({Edit::Insert, pos, text});
        redoStack = stack<Edit>(); // Clear the redoStack
    }

    void erase(int pos, int length) {
        if (pos + length > buffer.size()) return; // Check for valid range
        string removed = buffer.substr(pos, length);
        buffer.erase(pos, length);
        undoStack.push({Edit::Delete, pos, removed});
        redoStack = stack<Edit>(); // Clear the redoStack
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

    const string& getText() const {
        return buffer;
    }

private:
    string buffer;
    stack<Edit> undoStack, redoStack;

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
    cout << "Buffer: " << editor.getText() << endl;

    editor.insert(5, ", world");
    cout << "Buffer: " << editor.getText() << endl;

    editor.undo();
    cout << "Buffer: " << editor.getText() << endl;

    editor.redo();
    cout << "Buffer: " << editor.getText() << endl;

    editor.erase(0, 5);
    cout << "Buffer: " << editor.getText() << endl;

    editor.undo();
    cout << "Buffer: " << editor.getText() << endl;

    editor.redo();
    cout << "Buffer: " << editor.getText() << endl;

    return 0;
}
