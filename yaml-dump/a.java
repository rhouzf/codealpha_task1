package TD2;
import java.time.LocalDateTime;
import java.util.Arrays;

public class CompteBancaire {
    private String nomTitulaire;
    private double solde;
    private double tauxInteretAnnuel;
    private OperationBancaire[] operations;
    private int nombreOperations; // Pour garder une trace du nombre d'opérations ajoutées

  public CompteBancaire(String nomTitulaire, double solde, double tauxInteretAnnuel) {
        this.nomTitulaire = nomTitulaire;
        this.solde = solde;
        this.tauxInteretAnnuel = tauxInteretAnnuel;
        this.operations = new OperationBancaire[10];
        this.nombreOperations = 0;
    }

    private void ajouterOperation(OperationBancaire operation) {
        if (nombreOperations >= operations.length) {
            operations = Arrays.copyOf(operations, operations.length * 2);
        }
        operations[nombreOperations++] = operation;
    }

    public void depot(double montant, LocalDateTime date) {
        this.solde += montant;
        ajouterOperation(new OperationBancaire(date, montant));
    }
	
	public void retrait(double montant, LocalDateTime date) {
        this.solde -= montant;
        ajouterOperation(new OperationBancaire(date, -montant));
    }

    public double getSolde() {
        return solde;
    }

    public OperationBancaire[] getOperations() {
        return Arrays.copyOf(operations, nombreOperations); // Retourne seulement le sous-ensemble utilisé
    }

    public double calculInterets() {
        return solde * tauxInteretAnnuel;
    }

    public void affiche() {
        System.out.println("Nom du titulaire: " + nomTitulaire);
        System.out.println("Solde actuel: " + solde);
        System.out.println("Intérêts annuels: " + calculInterets());
        System.out.println("Historique des opérations:");
        for (int i = 0; i < nombreOperations; i++) {
            System.out.println(operations[i]);
        }
    }
}