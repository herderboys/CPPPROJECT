1. INSTRUKTION FÖR ATT BYGGA/KÖRA

Förutsättningar
För att kunna bygga och köra detta projekt krävs följande installerat på datorn:
C++ Kompilator: GCC (g++) med stöd för C++17 eller senare.
Byggverktyg: GNU Make.
Bibliotek: SDL3, SDL3_image, SDL3_ttf.

Bygga projektet
Öppna en terminal i projektets rotkatalog (där `Makefile` ligger) och kör kommandot: "make".

Detta kommer att kompilera källkoden och skapa en körbar fil i ./build/debug.
Efter att kompileringen är klar, starta spelet genom att köra följande kommando i terminalen: "./build/debug/play"

Resurser och sökvägar
Projektet kräver att mappen "resources" ligger i samma katalog som du kör spelet ifrån. Sökvägarna hanteras via en global konstant "gResPath".


2. TESTBESKRIVNING
Kontroller

- För att kunna kontrollera spelaren använder du W/A/S/D (upp, vänster, ner, höger). Detta styr rymdskeppets rörelse.
- Rymsdskeppet roterar baserad på musrörelse så att nosen på skeppet alltid är riktad mot muspekaren.
- Vänster musklick skjuter en "bullet" (skott) i riktningen som muspekaren är riktad mot, relativt till rymdskeppet.

Målet med spelet
Under spelets gång "faller" fiender (Enemy) från toppen av skärmen. Vissa fiender kommer att träffa jorden (Earth), som är visad längst ner på skärmen. Ditt mål som spelare (Player) är att skjuta och eliminera alla fiender så att jorden inte "dör" (går ner till 0 "health").

Om en fiende träffas av dina kulor (Bullets) så dör/försvinner den fienden. Om en fiende träffar jorden så tar jorden skada. Tillräckligt många träffar resulterar i att spelet slutar köra vilket är lika med "game over".

Du som spelare kan också skada jorden genom att skjuta mot den. Varje kula gör lika mycket skada som en fiende, så var försiktig!

Ett annat sätt att få game over är om du som spelare också "dör". Spelaren kan ta skada genom att krocka in i fiender och/eller jorden. När spelaren krockar in i en fiende eller jorden så studsar den iväg från det den kolliderat med baserat på vilket håll man krockade in ifrån. Exempelvis så studsar man rakt uppåt om man kolliderar med jorden genom att åka rakt nedåt in i jorden.