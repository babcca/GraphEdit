#ifndef INTERFACES_H__
#define INTERFACES_H__
#include <string>
#include <fstream>
#include "graph.h"
/**
 * Namespace pro rozhrani
 */
namespace Interfaces {
	/**
	 * \brief Inteface pro moduly
	 */
	struct IModule {
		IModule(const std::string & name_) : name(name_) {}
		virtual ~IModule() {}
		const std::string name; /**< Identifikacni nazev modulu */
	};
	/**
	 * \brief Interface pro zacleneni polozky do menu
	 */
	struct IMenu {
		IMenu(const std::string & menuName_, const std::string & extensions_) : menuName(menuName_), extensions(extensions_) {}
		const std::string menuName; /**< \brief Zobrazovany nazev v menu */
		const std::string extensions; /**< \brief Jake je typ koncovky u souboru */
	
	};

	/**
	 * \brief Interface pro exportery grafu
	 */
	struct IExporter : public IModule, IMenu {
		virtual ~IExporter() {}
		IExporter(const std::string & name, const std::string & menuName, const std::string & extensions)
			: IModule(name), IMenu(menuName, extensions) {}
		/** 
		 * \brief Ulozi graf do souboru.
		 * \param filename Nazev souboru
		 * \param graph Graf k ulozeni
		 * \return Uspesne ulozeni grafu
		 */
		virtual bool save_to_file(std::string & filename, const Graph::Graph & graph) const = 0;
	};
	/**
	 * \brief Interface pro importery
	 */
	struct IImporter : public IModule, IMenu {
		IImporter(const std::string & name, const std::string & menuName, const std::string & extensions) 
			: IModule(name), IMenu(menuName, extensions) {}
		virtual ~IImporter() {}
		/** 
		 * \brief Nacteni grafu ze souboru.
		 * \param filename Nazev souboru
		 * \param graph kam se ma nacteni graf ulozit
		 * \return Uspesne nacteni grafu
		 */
		virtual bool load_from_file(std::string & filename, Graph::Graph & graph) const = 0;
	};
	/**
	 * \brief Interface pro moduly starajici se o rozmisteni vrcholu
	 */
	struct IPlacement : public IModule {
	};
	/**
	 * \brief Interface pro rozsireni
	 */
	struct IExtensions : public IModule {
	};
};
#endif
