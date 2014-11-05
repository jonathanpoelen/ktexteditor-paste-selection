#ifndef PASTESELECTIONVIEW_H
#define PASTESELECTIONVIEW_H

#include <QObject>
#include <KXMLGUIClient>

class PasteSelectionView : public QObject, public KXMLGUIClient
{
	Q_OBJECT
	public:
		explicit PasteSelectionView(KTextEditor::View *view = 0);
		~PasteSelectionView();
	private slots:
		void insertPasteSelection();
	private:
		KTextEditor::View *m_view;
};

#endif
