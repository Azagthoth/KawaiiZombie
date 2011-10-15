/*
 * Singleton.h
 *
 *  Created on: 2 mars 2011
 *      Author: Lionel Vergé
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

template <class T>
class Singleton{
public:
  static T* Instance() {
      if(!m_pInstance) m_pInstance = new T;
      if (m_pInstance !=NULL)
    	  return m_pInstance;
      return NULL;
  }
protected:
  Singleton();
  ~Singleton();
private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
  static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance=NULL;

#endif /* SINGLETON_H_ */
