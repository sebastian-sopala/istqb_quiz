<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Platforma Quizowa ISTQB - CTFL 4.0</title>
    <style>
        :root {
            --primary-color: #2563eb;
            --primary-hover: #1d4ed8;
            --correct-color: #16a34a;
            --incorrect-color: #dc2626;
            --bg-color: #f8fafc;
            --card-bg: #ffffff;
            --text-main: #0f172a;
            --text-muted: #64748b;
            --border-radius: 12px;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: var(--bg-color);
            color: var(--text-main);
            line-height: 1.6;
            display: flex;
            justify-content: center;
            align-items: flex-start;
            min-height: 100vh;
            padding: 40px 20px;
        }

        .container {
            background-color: var(--card-bg);
            max-width: 900px;
            width: 100%;
            border-radius: var(--border-radius);
            box-shadow: 0 10px 25px rgba(0, 0, 0, 0.05);
            padding: 40px;
            position: relative;
        }

        /* --- MENU SETÓW --- */
        #menu-section h1 {
            text-align: center;
            color: var(--primary-color);
            margin-bottom: 10px;
        }

        .menu-subtitle {
            text-align: center;
            color: var(--text-muted);
            margin-bottom: 30px;
        }

        .sets-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
        }

        .set-card {
            border: 2px solid #e2e8f0;
            border-radius: var(--border-radius);
            padding: 25px;
            text-align: center;
            cursor: pointer;
            transition: all 0.3s ease;
            background: var(--bg-color);
        }

        .set-card:hover {
            border-color: var(--primary-color);
            transform: translateY(-5px);
            box-shadow: 0 4px 12px rgba(37, 99, 235, 0.1);
        }

        .set-card h3 {
            color: var(--text-main);
            margin-bottom: 10px;
        }

        .set-card p {
            color: var(--text-muted);
            font-size: 0.9rem;
        }

        /* --- QUIZ UI --- */
        .header-bar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 30px;
            padding-bottom: 15px;
            border-bottom: 2px solid #f1f5f9;
        }

        .header-bar h2 {
            font-size: 1.2rem;
            color: var(--text-muted);
        }

        .btn-back {
            background: none;
            border: none;
            color: var(--text-muted);
            font-weight: bold;
            cursor: pointer;
            font-size: 1rem;
            transition: color 0.2s;
        }

        .btn-back:hover {
            color: var(--primary-color);
        }

        .question {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 25px;
            color: #1e293b;
        }

        .options-list {
            display: flex;
            flex-direction: column;
            gap: 12px;
            margin-bottom: 25px;
        }

        .option {
            background-color: #f8fafc;
            border: 2px solid #e2e8f0;
            border-radius: 8px;
            padding: 16px 20px;
            cursor: pointer;
            transition: all 0.2s ease;
            font-size: 1.05rem;
        }

        .option:hover {
            background-color: #f1f5f9;
            border-color: #cbd5e1;
        }

        .option.selected-option {
            background-color: #eff6ff;
            border-color: var(--primary-color);
            color: var(--primary-hover);
        }

        .option.correct {
            background-color: #f0fdf4;
            border-color: var(--correct-color);
            color: #14532d;
            font-weight: 500;
        }

        .option.incorrect {
            background-color: #fef2f2;
            border-color: var(--incorrect-color);
            color: #7f1d1d;
        }

        #justification-container {
            background-color: #f1f5f9;
            padding: 20px;
            border-radius: 8px;
            border-left: 6px solid var(--primary-color);
            margin-bottom: 25px;
            font-size: 1rem;
            animation: fadeIn 0.4s ease;
        }

        .btn {
            display: block;
            width: 100%;
            background-color: var(--primary-color);
            color: #ffffff;
            border: none;
            padding: 16px;
            font-size: 1.1rem;
            font-weight: 600;
            border-radius: 8px;
            cursor: pointer;
            transition: background-color 0.3s ease;
            text-align: center;
        }

        .btn:hover {
            background-color: var(--primary-hover);
        }

        /* --- RESULTS UI --- */
        #results-container {
            text-align: center;
            padding: 40px 0;
        }

        .percentage {
            font-size: 4rem;
            font-weight: bold;
            color: var(--primary-color);
            display: block;
            margin: 20px 0;
        }

        .hidden {
            display: none !important;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
                transform: translateY(-10px);
            }

            to {
                opacity: 1;
                transform: translateY(0);
            }
        }

        @media (max-width: 600px) {
            .container {
                padding: 20px;
            }

            .header-bar {
                flex-direction: column;
                gap: 10px;
                align-items: flex-start;
            }

            .question {
                font-size: 1.1rem;
            }

            .option {
                padding: 14px;
                font-size: 0.95rem;
            }
        }
    </style>
</head>

<body>

    <div class="container">
        <!-- Menu Główne -->
        <div id="menu-section">
            <h1>Platforma Quizowa ISTQB</h1>
            <div class="menu-subtitle">Trwa ładowanie zestawów...</div>
            <div id="sets-grid" class="sets-grid">
            </div>
        </div>

        <!-- Sekcja Quizu -->
        <div id="quiz-section" class="hidden">
            <h2 id="quiz-title">Ładowanie...</h2>
            <div id="progress-text"></div>
            <div class="question" id="question-text">Trwa pobieranie pytań...</div>
            <div class="options-list" id="options-container"></div>
            <div id="justification-container" class="hidden"></div>
            <button id="next-btn" class="btn hidden">Następne pytanie</button>
            <button class="btn" style="margin-top: 20px; background-color: #64748b;" onclick="showMenu()">Wróć do Menu</button>
        </div>

        <!-- Wyniki -->
        <div id="results-container" class="hidden">
            <h2>Podsumowanie zestawu</h2>
            <div>Punkty: <span id="score-points">0</span> / <span id="total-points">0</span></div>
            <button class="btn" style="margin-top: 20px;" onclick="showMenu()">Wróć do Menu</button>
        </div>
    </div>

    <script>
        let currentQuizData = [];
        let currentQuestionIndex = 0;
        let score = 0;
        let hasAnswered = false;
        let selectedOptions = [];

        // Inicjalizacja: pobieranie pliku i generowanie menu zestawów
        document.addEventListener('DOMContentLoaded', async () => {
            const filename = 'first10_A_D.json'; // Domyślny, nowo wygenerowany plik z zestawami JSON
            const grid = document.getElementById('sets-grid');
            const subtitle = document.querySelector('.menu-subtitle');

            try {
                const response = await fetch(filename);
                if (!response.ok) throw new Error("Błąd pobierania pliku: " + response.statusText);
                
                const data = await response.json();
                subtitle.innerText = "Wybierz zestaw pytań, aby rozpocząć darmowy test.";
                grid.innerHTML = '';

                if (Array.isArray(data)) {
                    // Falls back for old format if needed
                    createSetButton('Zestaw z pliku', data);
                } else {
                    // New format (Object with keys as set names)
                    for (const [setName, questions] of Object.entries(data)) {
                        createSetButton(setName, questions);
                    }
                    
                    // Przycisk "Rozwiąż wszystkie łącznie"
                    const mixBtn = document.createElement('button');
                    mixBtn.className = 'btn';
                    mixBtn.innerText = 'Wszystkie zbiory (Mix)';
                    mixBtn.style.backgroundColor = 'var(--correct-color)';
                    mixBtn.style.gridColumn = '1 / -1'; 
                    mixBtn.onclick = () => {
                        let allQuestions = [];
                        Object.values(data).forEach(qArr => allQuestions = allQuestions.concat(qArr));
                        startQuizData('Wszystkie zbiory (Mix)', allQuestions);
                    };
                    grid.appendChild(mixBtn);
                }
            } catch (error) {
                console.error(error);
                subtitle.innerText = "Wystąpił błąd przy ładowaniu pliku. Upewnij się, że plik JSON istnieje i korzystasz z serwera lokalnego.";
            }
        });

        function createSetButton(title, questionsArray) {
            const btn = document.createElement('button');
            btn.className = 'btn';
            btn.innerText = title;
            btn.onclick = () => startQuizData(title, questionsArray);
            document.getElementById('sets-grid').appendChild(btn);
        }

        // Zmodyfikowana funkcja startu Quizu przyjmująca już wczytaną tablicę pytań
        function startQuizData(title, questionsData) {
            document.getElementById('menu-section').classList.add('hidden');
            document.getElementById('results-container').classList.add('hidden');
            document.getElementById('quiz-section').classList.remove('hidden');

            document.getElementById('quiz-title').innerText = title;
            document.getElementById('options-container').innerHTML = "";
            document.getElementById('justification-container').classList.add('hidden');
            document.getElementById('next-btn').classList.add('hidden');

            if (questionsData.length === 0) {
                document.getElementById('question-text').innerText = "Zestaw jest pusty!";
                return;
            }

            currentQuizData = questionsData;
            currentQuestionIndex = 0;
            score = 0;
            document.getElementById('total-points').innerText = currentQuizData.length;

            loadQuestion();
        }

        function loadQuestion() {
            hasAnswered = false;
            selectedOptions = [];
            const currentQ = currentQuizData[currentQuestionIndex];

            document.getElementById('progress-text').innerText = `Pytanie ${currentQuestionIndex + 1} / ${currentQuizData.length}`;
            document.getElementById('question-text').innerHTML = currentQ.question;
            const optionsContainer = document.getElementById('options-container');
            optionsContainer.innerHTML = '';

            document.getElementById('justification-container').classList.add('hidden');
            document.getElementById('next-btn').classList.add('hidden');

            const isMultiple = Array.isArray(currentQ.correctIndex);

            currentQ.options.forEach((option, index) => {
                const btn = document.createElement('div');
                btn.className = 'option';
                btn.innerHTML = option;
                
                btn.onclick = () => {
                    if (hasAnswered) return;
                    if (isMultiple) {
                        const idx = selectedOptions.indexOf(index);
                        if (idx > -1) {
                            selectedOptions.splice(idx, 1);
                            btn.classList.remove('selected-option');
                        } else {
                            selectedOptions.push(index);
                            btn.classList.add('selected-option');
                        }
                    } else {
                        handleOptionClickSingle(index, btn);
                    }
                };
                optionsContainer.appendChild(btn);
            });

            if (isMultiple) {
                const confirmBtn = document.createElement('button');
                confirmBtn.id = 'confirm-btn';
                confirmBtn.className = 'btn';
                confirmBtn.innerText = 'Sprawdź odpowiedź';
                confirmBtn.style.marginTop = '15px';
                confirmBtn.style.backgroundColor = '#f59e0b'; // amber color for check button
                confirmBtn.onclick = () => handleConfirmMultiple();
                optionsContainer.appendChild(confirmBtn);
            }
        }

        function handleConfirmMultiple() {
            if (selectedOptions.length === 0) return; // Należy wybrać chociaż jedną odpowiedź
            hasAnswered = true;
            
            const currentQ = currentQuizData[currentQuestionIndex];
            const allOptions = document.querySelectorAll('.option');
            
            const confirmBtn = document.getElementById('confirm-btn');
            if (confirmBtn) confirmBtn.style.display = 'none';

            let isAllCorrect = true;
            let correctCount = 0;

            selectedOptions.forEach(sel => {
                if (currentQ.correctIndex.includes(sel)) {
                    allOptions[sel].classList.add('correct');
                    correctCount++;
                } else {
                    allOptions[sel].classList.add('incorrect');
                    isAllCorrect = false;
                }
            });

            currentQ.correctIndex.forEach(corr => {
                if (!selectedOptions.includes(corr)) {
                    allOptions[corr].classList.add('correct'); 
                    isAllCorrect = false;
                }
            });

            if (isAllCorrect && correctCount === currentQ.correctIndex.length) {
                score++;
            }

            allOptions.forEach(opt => opt.style.pointerEvents = 'none');
            showJustificationAndNext();
        }

        function handleOptionClickSingle(selectedIndex, optionElement) {
            hasAnswered = true;
            const currentQ = currentQuizData[currentQuestionIndex];
            const allOptions = document.querySelectorAll('.option');

            if (selectedIndex === currentQ.correctIndex) {
                optionElement.classList.add('correct');
                score++;
            } else {
                optionElement.classList.add('incorrect');
                allOptions[currentQ.correctIndex].classList.add('correct');
            }

            allOptions.forEach(opt => opt.style.pointerEvents = 'none');
            showJustificationAndNext();
        }

        function showJustificationAndNext() {
            const currentQ = currentQuizData[currentQuestionIndex];
            const justContainer = document.getElementById('justification-container');
            justContainer.innerHTML = `<p>${currentQ.justification}</p>`;
            justContainer.classList.remove('hidden');

            const nextBtn = document.getElementById('next-btn');
            nextBtn.innerText = currentQuestionIndex === currentQuizData.length - 1 ? "Pokaż wyniki" : "Następne pytanie";
            nextBtn.classList.remove('hidden');
        }

        document.getElementById('next-btn').onclick = () => {
            currentQuestionIndex++;
            if (currentQuestionIndex < currentQuizData.length) {
                loadQuestion();
            } else {
                document.getElementById('quiz-section').classList.add('hidden');
                document.getElementById('results-container').classList.remove('hidden');
                document.getElementById('score-points').innerText = score;
            }
        };

        function showMenu() {
            document.getElementById('quiz-section').classList.add('hidden');
            document.getElementById('results-container').classList.add('hidden');
            document.getElementById('menu-section').classList.remove('hidden');
        }
    </script>
</body>

</html>