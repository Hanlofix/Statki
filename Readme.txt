Po odpaleniu programu na konsoli wyswietla się Menu Główne, na którym znajdują się  trzy opcje:
1.ZAGRAJ.
2.O GRZE.
3.ZAKONCZ.
Opcja nr.3 kończy program,
Opcja nr.2 wyświetla krótki opis gry, autor życzy miłej gry,
Opcja nr.1 przenosi nas do menu wyboru rodzaju gry:
W menu wyboru rodzaju gry mamy też 3 opcje:
1.GRACZ VS KOMPUTER.
2.GRACZ VS GRACZ.
3.WROC DO MENU GLOWNEGO.
*W każdym rodzaju gry gracz będzie mógł wybrać czy chce ustawić statki losowo, czy też ręcznie.
Jeżeli gracz będzie ustawiał statki losowo, to przed przejściem do rozgrywki jest możliwość ponownego 
losowania ustawienia statków nielimitowaną ilość razy.
*Ponadto w trybie gry z komputerem gracz wybiera też poziom trudności rozgrywki przed przystąpieniem do gry.
*Cały schemat gry znajduje się na załączonym zdjęciu.
*Na każdym etapie wyboru parametrów gry (oprócz rozgrywki) można się cofnąć do menu  głównego.
*Jeżeli ustawiamy statki ręcznie to:
Wyświetla się Tryb Ustawiania, który informuje nas  jaki typ statku właśnie ustawiamy(czy jest to 1,2,3 czy 4-masztowiec)
Należy wybrać czy statek ma mieć orientację pionową czy poziomą, a następnie współrzędną x oraz y
(jest to pierwsze pole statku od którego statek jest ustawiany w dół lub w prawo - zależy w jakiej jest orientacji).
Po wybraniu jednego czteromasztowca, dwóch trójmasztowców, trzech dwumasztowców oraz czterech jednomasztowców
rozpoczyna się właściwa rozgrywka.

*W trakcie rozgrywki po bokach plansz wyświetlany będzie stan każdego statku z każdej planszy, żeby można było 
łatwiej zorientować się na jakim etapie jest dana rozgrywka
Pod planszami będzie wyświetlana informacja, czyj jest aktualnie ruch oraz będzie można wpisywać, gdzie ma zostać oddany strzał(współrzędne x oraz y).
*Po zakończeniu rozgrywki wyświetlana jest informacja kto wygrał, a następnie po naciśnięciu dowolnego klawisza
przenosimy się z powrotem do Menu Głównego.
*W trybie gry z komputerem, jeżeli wygra komputer to wyświetli nam się położenie statków komputera których nie zatopiliśmy.
Gra nie pozwala na nieprawidłowe ustawianie statków, czy też strzelanie dwa razy w to samo miejsce( wyświetli się wtedy "Już tu strzelałeś!")
Gra jest też "idioto odporna" - jest zabezpieczona przed wpisywaniem jakichkolwiek innych znaków niż dozwolone .

NIEBIESKIE KRZAKI('#') - WODA
ZIELONE KÓŁKA('O') - STATKI
CZERWONE KRZYŻYKI ('X')- TRAFIENIA
FIOLETOWE 'M' - PUDŁO(MISS)

/*Jest to wersja alfa, więc napewno jest dużo do poprawy. Na pewno będę chciał, żeby:
 z boku planszy wyświetlał się aktualny stan gry; 
jak zatopię statek to żeby się wyświtlało jaki typ masztowca;
wprowadzić zabezpieczenie przed wpisywanie znaków innych niż 'int' bo na razie się wykrzacza;   -------->> Raczej wszystko mi się udało zrealizować
na każdym etapie gry (oprócz rozgrywki) można było zakończyć (chociać to może być trudne);
Losowe ustawianie statków dla gracza;
żeby po wygranej komputera można było zobaczyć jak miał rozmieszczone statki */

Poza powyższymi punktami, wprowadziłem także:
1."intelligentMove()" - czyli pseudo inteligentne ruchy komputera. Musiałem do tego przerobić planszę, tak żeby były dwa puste miejsca po bokach, 
ale dzięki temu mogłem wprowadzić poziomy trudności w rozgrywce z komputerem (poziom łatwy->ruchy są przypadkowe,
 poziom średni-> połowa ruchów przypadkowych, a połowa ruchów inteligentnych, poziom trudny->same ruchy inteligentne).
2."Animację" strzału.
3.Losowe wybieranie gracza zaczynającego - zarówno w rozgrywce z komputerem jak i w trybie gry gracz vs gracz.
4.No i oczywiście tryb gry gracz vs gracz (Każdy gracz w swoim ruchu widzi swoje statki, ale nie statki przeciwnika,
pomiędzy ruchami graczy następuje przekazanie komputera przeciwnikowi z przejściowym ekranem, żeby żaden gracz nie widział statków oponenta)

Dane do testu:
TRYB USTAWIANIA:
4-masztowiec: poziomo, x-1, y-1;
3-masztowiec:: poziomo, x-3, y-1;
3-masztowiec: poziomo, x-5, y-1;
2-masztowiec: pionowo, x-1, y-7;
2-masztowiec: poziomo, x-9, y-1;
2-masztowiec: pionowo, x-6, y-6;
1-masztowiec: x-4, y-10;
1-masztowiec: x-6, y-10;
1-masztowiec: x-8, y-10;
1-masztowiec: x-10, y10;

*TRUDNO MI TAK NAPRAWDĘ NAPISAĆ SCHEMAT TESTOWANIA MOJEJ GRY. PO PROSTU MOŻNA POWCHODZIĆ WE WSZYSTKI OPCJE,
PRÓBOWAĆ WRÓCIĆ DO MENU GŁÓWNEGO, ZAGRAĆ Z KOMPUTEREM NA RÓŻNYCH POZIOMACH TRUDNOŚCI, ZAGRAĆ Z KIMŚ INNYM,
LOSOWO LUB RĘCZNIE POUSTAWIAĆ STATKI

ROZGRYWKA:
wpisywać wspolrzedne x oraz y (od 1 do 10) aż do roztrzygnięcia rozgrywki


PROGRAM NIE POZWALA USTAWIAC STATKOW NIEZGODNIE Z REGULAMI, WPISYWAC WARTOSCI WIEKSZYCH LUB MNIEJSZYCH NIZ ROZMIAR PLANSZY,
WPISYWAC ZNAKOW INNYCH NIZ TYP ZNAKU OCZEKIWANY PRZEZ KONSOLE ANI STRZELAC DWA RAZY W TO SAMO MIEJSCE.

