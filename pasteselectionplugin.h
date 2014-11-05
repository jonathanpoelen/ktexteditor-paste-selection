#ifndef PASTESELECTIONPLUGIN_H
#define PASTESELECTIONPLUGIN_H

#include <KTextEditor/Plugin>

namespace KTextEditor
{
	class View;
}

class PasteSelectionView;

class PasteSelectionPlugin
  : public KTextEditor::Plugin
{
  public:
    // Constructor
    explicit PasteSelectionPlugin(QObject *parent = 0, const QVariantList &args = QVariantList());
    // Destructor
    virtual ~PasteSelectionPlugin();

    void addView (KTextEditor::View *view);
    void removeView (KTextEditor::View *view);
 
    void readConfig();
    void writeConfig();
 
//     void readConfig (KConfig *);
//     void writeConfig (KConfig *);
 
  private:
    QList<class PasteSelectionView*> m_views;
};

#endif
