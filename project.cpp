/*
this is the mission 
3. Stack-Based Undo/Redo Text Editor
System Requirements:
 - Maintain a std::string buffer.
 - insert(pos, text) and erase(pos, len) modify buffer.
 - Unlimited undo()/redo() via two LIFO stacks.
System Design:
struct Edit { enum Type {Insert, Delete} type; int pos; std::string text; };
class TextEditor {
public:
    void insert(int pos, const std::string& text);
    void erase(int pos, int length);
    void undo(); void redo();
    const std::string& getText() const;
private:
    std::string buffer;
    std::stack<Edit> undoStack, redoStack;
    void apply(const Edit& e); void revert(const Edit& e);
};
Role Explanation (2–3 sentences):
Explain how two stacks cleanly model undo and redo operations.
Function Skeletons (fill in // TODO):
void TextEditor::insert(int pos, const std::string& text) {
    // TODO: buffer.insert(pos, text);
    undoStack.push({Edit::Insert, pos, text});
    // TODO: clear redoStack
}
void TextEditor::erase(int pos, int length) {
    // TODO: std::string removed = buffer.substr(pos, length);
    // TODO: buffer.erase(pos, length);
    undoStack.push({Edit::Delete, pos, removed});
    // TODO: clear redoStack
}
void TextEditor::undo() {
    if (undoStack.empty()) return;
    Edit e = undoStack.top(); undoStack.pop();
    // TODO: revert(e);
    redoStack.push(e);
}
void TextEditor::redo() {
    if (redoStack.empty()) return;
    Edit e = redoStack.top(); redoStack.pop();
    // TODO: apply(e);
    undoStack.push(e);
}
void TextEditor::apply(const Edit& e) {
    if (e.type == Edit::Insert) {
        // TODO: buffer.insert(e.pos, e.text);
    } else {
        // TODO: buffer.erase(e.pos, e.text.size());
    }
}
void TextEditor::revert(const Edit& e) {
    if (e.type == Edit::Insert) {
        // TODO: buffer.erase(e.pos, e.text.size());
    } else {
        // TODO: buffer.insert(e.pos, e.text);
    }
}
Testing:
Perform a sequence of edits, undos, and redos; print buffer after each operation.
4. Queue-Driven Print Spooling Simulator
*/
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
