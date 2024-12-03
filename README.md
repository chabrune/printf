# ft_printf - Recoder printf()

Une implémentation personnalisée de la fonction printf de la libc.

## 📋 Description

ft_printf est un projet qui consiste à recréer la célèbre fonction printf en C. Ce projet permet d'explorer les fonctions variadiques et de créer une fonction de formatage flexible et extensible.

## ⚙️ Fonctionnalités

### Conversions Supportées
| Spécificateur | Description |
|---------------|-------------|
| %c | Caractère simple |
| %s | Chaîne de caractères |
| %p | Pointeur en hexadécimal |
| %d | Nombre décimal (base 10) |
| %i | Entier en base 10 |
| %u | Nombre décimal non signé |
| %x | Nombre hexadécimal (minuscules) |
| %X | Nombre hexadécimal (majuscules) |
| %% | Signe pourcentage |

## 🛠️ Compilation

```bash
make        # Compile la bibliothèque
make bonus  # Ajoute les fonctionnalités bonus
make clean  # Nettoie les fichiers objets
make fclean # Nettoie tout
make re     # Recompile tout
```

## 📚 Utilisation

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    return (0);
}
```

## 🔍 Spécifications Techniques

- **Prototype** : `int ft_printf(const char *, ...)`
- **Retour** : Nombre de caractères imprimés
- **Fonctions autorisées** : malloc, free, write, va_start, va_arg, va_copy, va_end
- **Bibliothèque** : Utilisation de libft autorisée
- **Compilation** : -Wall -Wextra -Werror

## ⚠️ Notes Importantes

- Pas de gestion de buffer comme le printf original
- Création de la bibliothèque avec ar (pas de libtool)
- La bibliothèque libftprintf.a doit être à la racine
- Les bonus ne seront évalués que si la partie obligatoire est parfaite

---
*Projet réalisé dans le cadre du cursus de l'école 42*
