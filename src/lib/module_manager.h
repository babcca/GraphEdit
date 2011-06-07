#include <map>
#include <string>
#include "interfaces.h"
/**
 * Sparvce trid modulu
 */
template<typename ObjectType>
class ObjectManager {
public:
	ObjectManager() {}
	/** \brief Iterator */
	typedef typename std::map<std::string, ObjectType *>::iterator iterator;
	/** \brief Konstatni iterator */
	typedef typename std::map<std::string, ObjectType *>::const_iterator const_iterator;
	/** \brief Typ ulozenych dat */
	typedef typename std::pair<std::string, ObjectType *> data_type;

	/** \brief Iterator prvniho objekt */
	iterator begin() { return list.begin(); }
	/** \brief Iterator posledniho objektu */
	iterator end() { return list.end(); }
	/** \brief Konstatni iterator prvniho objektu */
	const_iterator begin() const { return list.begin(); }
	/** \brief Konstatni iterator posledniho objektu */
	const_iterator end() const { return list.end(); }
	
	/** 
	 * \brief Prida obejekt do seznamu 
	 * \param object Instance objektu
	 * \return
	 */
	void add(ObjectType * object) {
		list.insert(data_type(object->name, object));
	}
	
	/** 
	 * \brief Ziska objekt podle jmena
	 * \param name Jmeno objektu
	 * \return Objekt
	 */
	const_iterator operator[] (const std::string & name) const {
		return list.find(name);
	};

	/** 
	 * Stara se o zanik vsech registrovanych objektu. 
	 */
	~ObjectManager() {
		iterator it = begin();
		while (it != end()) {
			delete it->second;
			it->second = 0;
			++it;
		}
	}
private:
	/* Zakaz Kopirovani */
	ObjectManager(ObjectManager & obj) {};
	ObjectManager & operator= (const ObjectManager & obj) {};
	std::map<const std::string, ObjectType *> list; /**< Struktura pro udrzeni objektu [jmeno]-> Exporter */
};

/**
 * \brief Sparvce modului.
 *
 * Rozdeluj moduly do ruznych trid podle typu
 * Mel by se starat o nacitani modulu atp.
 * Kazdy modul se musi zaregistrovat do spravne tridy <br>
 * tridy jsou: <br> 
 * exporter - Slouzi pro ukladani dat do souboru.<br>
 * importer - Slouzi pro nacitani dat ze souboru.<br>
 * placement - Stara se o rozmisteni vrcholy do prostoru (Barycentricky, Boyer-Myrvold).<br>
 * extensions - Moduly pro praci s grafem.<br>
 */

class ModuleManager {
public:
	typedef ObjectManager<Interfaces::IExporter> exporter_type;
 	typedef ObjectManager<Interfaces::IImporter> importer_type;
 	typedef ObjectManager<Interfaces::IPlacement> placement_type;
 	typedef ObjectManager<Interfaces::IExtensions>	extensions_type;
	
	exporter_type exporter; /**< \brief Trida exporteru. */
	importer_type importer; /**< \brief Trida importeru */
	placement_type placement; /**< \brief Trida starajici se o rozlozeni vrcholu */
	extensions_type extensions; /**< \brief Trida starajici se o externi moduly */
};


