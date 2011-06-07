#include <QtGui>
#include "module_manager.h"
#include "raw.h"

/**
 * \brief Trida hlavniho okna
 *
 * Stara se o spracovani vsech udalosti od uzivatele
 */
class MainW : public QMainWindow {
	Q_OBJECT
public:
	MainW();
	~MainW() {}
private slots:
	/**
	 * \brief Slot pro importovani souboru
	 */
	void ImportFile();
	/**
	 * \brief Slot pro exportovani souboru
	 */
	void ExportFile();
	
private:
	/**
	 * \brief Vygenerovani menu z registrovanych importeru
	 */
	void GenerateImporterMenu(QMenu * importerMenu);
	void GenerateExporterMenu(QMenu * exporterMenu);

	typedef ModuleManager::importer_type importer_type; /**< Datovy typ pro importer */
	typedef ModuleManager::exporter_type exporter_type; /**< Datovy typ pro exporter */
	typedef ModuleManager::placement_type placement_type; /**< Datovy typ pro placement */
	typedef ModuleManager::extensions_type extensions_type; /**< Datovy typ pro extensions */
	ModuleManager mm; /**< Spravce modulu v aplikaci */
	QMenu * fileMenu;
	QMenu * importMenu;
};

