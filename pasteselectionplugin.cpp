#include "pasteselectionplugin.h"
#include "pasteselectionview.h"

#include <KTextEditor/Document>
#include <KTextEditor/View>

#include <KPluginFactory>
#include <KPluginLoader>
#include <KLocale>
#include <KAction>
#include <KActionCollection>

#include <QApplication>
#include <QClipboard>

K_PLUGIN_FACTORY(PasteSelectionPluginFactory, registerPlugin<PasteSelectionPlugin>("ktexteditor_pasteselection");)
K_EXPORT_PLUGIN(PasteSelectionPluginFactory("ktexteditor_pasteselection", "ktexteditor_plugins"))

PasteSelectionPlugin::PasteSelectionPlugin(QObject *parent, const QVariantList &args)
: KTextEditor::Plugin(parent)
{
	Q_UNUSED(args);
}

PasteSelectionPlugin::~PasteSelectionPlugin()
{
}

void PasteSelectionPlugin::addView(KTextEditor::View *view)
{
	PasteSelectionView *nview = new PasteSelectionView(view);
	m_views.append(nview);
}

void PasteSelectionPlugin::removeView(KTextEditor::View *view)
{
	for(int z = 0; z < m_views.size(); z++)
	{
		if(m_views.at(z)->parentClient() == view)
		{
			PasteSelectionView *nview = m_views.at(z);
			m_views.removeAll(nview);
			delete nview;
		}
	}
}

void PasteSelectionPlugin::readConfig()
{
}

void PasteSelectionPlugin::writeConfig()
{
}

PasteSelectionView::PasteSelectionView(KTextEditor::View *view)
: QObject(view)
, KXMLGUIClient(view)
, m_view(view)
{
	setComponentData(PasteSelectionPluginFactory::componentData());

	KAction *action = new KAction(i18n("Paste selection"), this);
	actionCollection()->addAction("tools_pasteselection", action);
	action->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_Insert);
	connect(action, SIGNAL(triggered()), this, SLOT(insertPasteSelection()));

	setXMLFile("pasteselectionui.rc");
}

PasteSelectionView::~PasteSelectionView()
{
}

void PasteSelectionView::insertPasteSelection()
{
	m_view->document()->insertText(m_view->cursorPosition(), QApplication::clipboard()->text(QClipboard::QClipboard::Selection));
}

#include "pasteselectionview.moc"
