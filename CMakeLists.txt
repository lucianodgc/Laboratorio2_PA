cmake_minimum_required(VERSION 3.16)
project(LaboratorioFinal2)

set(CMAKE_CXX_STANDARD 17)

add_executable(LaboratorioFinal2
        main.cpp
        Cliente.cpp
        Comentario.cpp
        Controlador.cpp
        Compras.cpp
        Estructuras.cpp
        Fabrica.cpp
        Producto.cpp
        ProductoCompras.cpp
        Promocion.cpp
        PromocionProducto.cpp
        Usuario.cpp
        Vendedor.cpp

        ICollection/Integer.cpp
        ICollection/String.cpp
        ICollection/collections/List.cpp
        ICollection/collections/ListIterator.cpp
        ICollection/collections/ListNode.cpp
        ICollection/collections/OrderedDictionary.cpp
        ICollection/collections/OrderedDictionaryEntry.cpp
        ICollection/interfaces/ICollectible.cpp
        ICollection/interfaces/ICollection.cpp
        ICollection/interfaces/IDictionary.cpp
        ICollection/interfaces/IIterator.cpp
        ICollection/interfaces/IKey.cpp
        ICollection/interfaces/OrderedKey.cpp
)
