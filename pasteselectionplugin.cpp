/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* \author Jonathan Poelen <jonathan.poelen@gmail.com>
*/

#include "pasteselectionplugin.h"

#include <kpluginfactory.h>
#include <kactioncollection.h>
#include <klocale.h>
#include <kaboutdata.h>

#include <interfaces/icore.h>
#include <interfaces/idocumentcontroller.h>

#include <KTextEditor/Document>

#include <QApplication>
#include <QClipboard>


K_PLUGIN_FACTORY_WITH_JSON(PasteSelectionFactory, "kdevpasteselection.json", registerPlugin<KDevPasteSelectionPlugin>();)

namespace
{
  void pasteselection()
  {
    if (auto* doc = KDevelop::ICore::self()->documentController()->activeDocument())
    {
      doc->textDocument()->insertText(
        doc->cursorPosition(),
        QApplication::clipboard()->text(QClipboard::QClipboard::Selection)
      );
    }
  }
}

KDevPasteSelectionPlugin::KDevPasteSelectionPlugin(QObject *parent, const QVariantList &)
:KDevelop::IPlugin("kdevpasteselection", parent)
{
  setXMLFile("kdevpasteselection.rc");

  auto ac = actionCollection();
  auto addAction = [ac,this](QString && name, char const * desc, auto act){
    QAction* action = ac->addAction(qMove(name));
    action->setText(i18n(desc));
    connect(action, &QAction::triggered, this, act);
    return action;
  };

  QAction* paste = addAction(QStringLiteral("pasteselection"), "Paste selection", pasteselection);
  paste->setIcon(QIcon::fromTheme(QStringLiteral("edit-paste")));
  ac->setDefaultShortcut(paste, Qt::CTRL + Qt::SHIFT + Qt::Key_Insert);
}

KDevPasteSelectionPlugin::~KDevPasteSelectionPlugin() = default;

#include "pasteselectionplugin.moc"
