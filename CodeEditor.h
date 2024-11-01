#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QObject>

namespace CodeEditorStates
{
enum codeEditorMode {commandMode, fullEditMode};
}

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = nullptr);

    inline void setNameEditingFile(const QString&);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

private :
    void changeModeToFullEdit();
    void changeModeToCommandInput();

private slots:
    void keyPressEvent(QKeyEvent *event) override;
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);
    inline void setTabsSize(int size) noexcept;

private:
    QString nameEditingFile = "untitled";
    int tabsSize = 4;
    CodeEditorStates::codeEditorMode mode = CodeEditorStates::codeEditorMode::fullEditMode;
    QWidget *lineNumberArea;
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor){}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};

#endif // CODEEDITOR_H
