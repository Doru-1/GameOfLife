# GameOfLife
Acest proiect implementează simularea automatelor celulare în stilul Conway’s Game of Life folosind C. 

**Autori:** Stere Teodor-Ioanin
**Limbaj:** C  
**Tema:** Conway's Game of Life - Proiectare Algoritmi

## 📖 Descriere generală

Acest proiect simulează "Game of Life", un automat celular creat de John Conway, în care evoluția unei grile de celule se bazează pe reguli simple de vecinătate. Deși regulile sunt minimaliste, ele pot duce la comportamente complexe.

Programul este structurat în mai multe task-uri:

- **Task 1:** Simularea standard a Game of Life pentru un număr dat de generații.
- **Task 2:** Stocarea diferențelor între generații într-o stivă de liste.
- **Task 3:** Construirea unui arbore binar care compară evoluții cu reguli diferite.
- **Task 4:** Determinarea celui mai lung lanț Hamiltonian în grafuri generate de celulele vii.

---

## ⚙️ Cum se utilizează

### 🔧 Cerințe:
- Compilator C (GCC sau similar)
- Sistem de operare compatibil cu C standard (Linux, Windows, macOS)

### 🏗️ Compilare:

```bash
gcc main.c task1.c task2.c task3.c common.c
