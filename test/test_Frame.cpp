//
// Created by cappe on 06/02/24.
//

#include <gtest/gtest.h>
//#include <gmock/gmock.h>  // Include GMock per il testing dei mock (se necessario)

// Includi la tua classe Frame
#include "Frame.h"

// Definisci una classe di mock per simulare il comportamento di ItemController (se necessario)
class MockItemController : public ItemController {
public:
    MOCK_METHOD(void, addTask, (const wxString&, const wxDateTime&, Priority));
    // Aggiungi altri metodi mock se necessario
};

// Test per l'aggiunta di un nuovo task
TEST(FrameTest, AddTask) {
    // Crea un oggetto Frame
    TaskList taskList;  // Assicurati di avere una TaskList funzionante
    MockItemController mockItemController;  // Usa il mock se necessario
    Frame frame(&taskList, &mockItemController, "Test Frame", wxDefaultPosition, wxDefaultSize);

    // Simula l'input utente
    wxString taskName = "Nuovo Task";
    wxDateTime dateTime = wxDateTime::Now() + wxTimeSpan::Days(1);
    Priority priority = Priority::High;

    // Usa il mock se necessario
    EXPECT_CALL(mockItemController, addTask(taskName, dateTime, priority));

    // Chiamata al metodo di aggiunta del task nella tua classe Frame
    frame.addTaskButton(wxCommandEvent());

    // Verifica che l'aggiunta sia avvenuta correttamente
    // Ad esempio, puoi verificare che la lista dei task sia stata aggiornata correttamente
    // e che il testo nell'wxTextCtrl sia ripristinato dopo l'aggiunta.
    // Aggiungi qui le asserzioni specifiche del tuo codice.
    // ASSERT_TRUE(taskList.contieneIlTask(taskName)); // Sostituisci con la tua logica effettiva

    // ASSERT_EQ(frame.GetTaskTextCtrlValue(), "Enter New Task Name"); // Sostituisci con la tua logica effettiva
}
t